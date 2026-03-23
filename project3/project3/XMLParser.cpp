#include "XMLParser.hpp"

XMLParser::XMLParser()
{
	tokenized = false;
	parsed = false;
} 

bool XMLParser::tokenizeInputString(const std::string &inputString)
{	
	//reset everything from previous calls
	clear();

	//check for empty/whitespace-only input
	bool allWhitespace = true;
	for (size_t i = 0; i < inputString.length(); i++)
	{
		if (!std::isspace(inputString[i]))
		{
			allWhitespace = false;
			break;
		}
	}
	if (inputString.empty() || allWhitespace) return false;

	size_t currentPos = 0;
	std::string markup;
	std::string content;
	std::string tagName;

	//walk through the string finding < > pairs
	while(currentPos < inputString.length())
	{
		//find next open bracket
		size_t openBracketPos = inputString.find('<',currentPos);
		if (openBracketPos == std::string::npos)
		{
			//no more tags, everything left is content
			content = inputString.substr(currentPos, inputString.length());

			if (content.empty()) return false;

			//a '>' sitting in content with no '<' before it is bad
			for (size_t i = 0; i < content.length(); i++)
			{
				if (content[i] == '>') return false;
			}

			//check if its all whitespace
			bool blank = true;
			for (size_t i = 0; i < content.length(); i++)
			{
				if (!std::isspace(content[i]))
				{
					blank = false;
					break;
				}
			}

			//only store content if its not blank
			if (!blank)
			{
				TokenStruct token;
				token.tokenType = CONTENT;
				token.tokenString = content;
				tokenizedInputVector.push_back(token);
			}
			break;
		}

		//grab any content between the last tag and this one
		if (currentPos < openBracketPos)
		{
			content = inputString.substr(currentPos, openBracketPos - currentPos);

			//same thing, stray '>' in content is invalid
			for (size_t i = 0; i < content.length(); i++)
			{
				if (content[i] == '>') return false;
			}

			bool blank = true;
			for (size_t i = 0; i < content.length(); i++)
			{
				if (!std::isspace(content[i]))
				{
					blank = false;
					break;
				}
			}

			if (!blank)
			{
				TokenStruct token;
				token.tokenType = CONTENT;
				token.tokenString = content;
				tokenizedInputVector.push_back(token);
			}
		}

		//find matching close bracket
		size_t closeBracketPos = inputString.find('>',openBracketPos);

		//no closing bracket = bad
		if (closeBracketPos == std::string::npos) return false;

		//check for nested '<' inside the tag
		for (size_t i = openBracketPos + 1; i < closeBracketPos; i++)
		{
			if (inputString[i] == '<') return false;
		}

		//extract whats between the brackets
		markup = inputString.substr(openBracketPos + 1, closeBracketPos - openBracketPos - 1);
		//empty brackets like <> is invalid
		if (markup.empty()) return false;

		//figure out what type of tag this is
		TokenStruct token;
		if (markup[0] == '?' && markup[markup.length() - 1] == '?')
		{
			//declaration like <?xml version="1.0"?>
			token.tokenType = DECLARATION;
			token.tokenString = markup.substr(1, markup.length() - 2);
		}
		else if (markup[0] == '/')
		{
			//end tag like </html>
			tagName = markup.substr(1);
			token.tokenType = END_TAG;
			token.tokenString = tagName;
		}
		else if (markup[markup.length() - 1] == '/')
		{
			//empty tag like <br/> — strip the / then check for attributes
			std::string stripped = markup.substr(0, markup.length() - 1);
			size_t spacePos = stripped.find(' ');
			if (spacePos != std::string::npos)
			{
				tagName = stripped.substr(0, spacePos);
			}
			else
			{
				tagName = stripped;
			}
			token.tokenType = EMPTY_TAG;
			token.tokenString = tagName;
		}
		else
		{	
			//start tag — check for attributes after a space
			size_t spacePos = markup.find(' ');
			if (spacePos != std::string::npos)
			{
				tagName = markup.substr(0, spacePos);
			}
			else
			{
				tagName = markup;
			}
			token.tokenType = START_TAG;
			token.tokenString = tagName;
		}

		currentPos = closeBracketPos + 1;

		//validate tag name characters (skip for declarations)
		if (token.tokenType != DECLARATION)
		{
			if (tagName.empty()) return false;
			//first char must be letter or underscore
			if (!std::isalpha(tagName[0]) && tagName[0] != '_') return false;
			//rest can be letters, digits, underscores, hyphens, periods
			for (size_t i = 1; i < tagName.length(); i++)
			{
				char c = tagName[i];
				if (!std::isalnum(c) && c != '_' && c != '-' && c != '.') return false;
			}
		}

		tokenizedInputVector.push_back(token);
	}
	tokenized = true;
	return true;
}

bool XMLParser::parseTokenizedInput()
{
	if (tokenizedInputVector.empty()) return false;

	int depth = 0;        //how deep we are in nested elements
	bool rootClosed = false; //tracks if root element has been closed

	for (size_t i = 0; i < tokenizedInputVector.size(); i++)
	{
		TokenStruct token = tokenizedInputVector[i];

		if (token.tokenType == DECLARATION)
		{
			//declarations only go before the root element
			if (depth > 0 || rootClosed) return false;
		}
		else if (token.tokenType == START_TAG)
		{
			//cant have anything after root closes
			if (rootClosed) return false;
			parseStack.push(token.tokenString);
			elementNameBag.add(token.tokenString);
			depth++;
		}
		else if (token.tokenType == END_TAG)
		{
			//check if theres a matching start tag on the stack
			if (parseStack.isEmpty()) return false;
			if (parseStack.peek() != token.tokenString) return false;
			parseStack.pop();
			depth--;
			//if we're back to depth 0, root is done
			if (depth == 0) rootClosed = true;
		}
		else if (token.tokenType == EMPTY_TAG)
		{
			//empty tag cant be the root and cant come after root closes
			if (rootClosed) return false;
			if (depth == 0) return false;
			elementNameBag.add(token.tokenString);
		}
		else if (token.tokenType == CONTENT)
		{
			//content has to be inside an element
			if (depth == 0) return false;
		}
	}

	//if stack isnt empty, theres unmatched start tags
	if (!parseStack.isEmpty()) return false;

	parsed = true;
	return true;
}

void XMLParser::clear()
{
	tokenizedInputVector.clear();
	elementNameBag.clear();
	parseStack.clear();
	tokenized = false;
	parsed = false;
}

std::vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

bool XMLParser::containsElementName(const std::string &inputString) const
{
	//cant call this before tokenizing and parsing
	if (!tokenized || !parsed) throw std::logic_error("Input not tokenized and parsed");
	return elementNameBag.contains(inputString);
}

int XMLParser::frequencyElementName(const std::string &inputString) const
{
	if (!tokenized || !parsed) throw std::logic_error("Input not tokenized and parsed");
	return elementNameBag.getFrequencyOf(inputString);
}