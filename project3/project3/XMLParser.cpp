#include "XMLParser.hpp"

XMLParser::XMLParser()
{
	tokenized = false;
	parsed = false;
} 

bool XMLParser::tokenizeInputString(const std::string &inputString)
{	
	clear();

	// check for empty/whitespace-only input
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

	while(currentPos < inputString.length())
	{
		size_t openBracketPos = inputString.find('<',currentPos);
		if (openBracketPos == std::string::npos)
		{
			content = inputString.substr(currentPos, inputString.length());

			if (content.empty()) return false;

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
			break;
		}

		if (currentPos < openBracketPos)
		{
			content = inputString.substr(currentPos, openBracketPos - currentPos);

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

		size_t closeBracketPos = inputString.find('>',openBracketPos);

		if (closeBracketPos == std::string::npos) return false;

		for (size_t i = openBracketPos + 1; i < closeBracketPos; i++)
		{
			if (inputString[i] == '<') return false;
		}

		markup = inputString.substr(openBracketPos + 1, closeBracketPos - openBracketPos - 1);
		if (markup.empty()) return false;

		TokenStruct token;
		if (markup[0] == '?' && markup[markup.length() - 1] == '?')
		{
			token.tokenType = DECLARATION;
			token.tokenString = markup.substr(1, markup.length() - 2);
		}
		else if (markup[0] == '/')
		{
			tagName = markup.substr(1);
			token.tokenType = END_TAG;
			token.tokenString = tagName;
		}
		else if (markup[markup.length() - 1] == '/')
		{
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

		if (token.tokenType != DECLARATION)
		{
			if (tagName.empty()) return false;
			if (!std::isalpha(tagName[0]) && tagName[0] != '_') return false;
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

	int depth = 0;
	bool rootClosed = false;

	for (size_t i = 0; i < tokenizedInputVector.size(); i++)
	{
		TokenStruct token = tokenizedInputVector[i];

		if (token.tokenType == DECLARATION)
		{
			// declarations only allowed before the root opens
			if (depth > 0 || rootClosed) return false;
		}
		else if (token.tokenType == START_TAG)
		{
			// nothing allowed after root is closed
			if (rootClosed) return false;
			parseStack.push(token.tokenString);
			elementNameBag.add(token.tokenString);
			depth++;
		}
		else if (token.tokenType == END_TAG)
		{
			if (parseStack.isEmpty()) return false;
			if (parseStack.peek() != token.tokenString) return false;
			parseStack.pop();
			depth--;
			if (depth == 0) rootClosed = true;
		}
		else if (token.tokenType == EMPTY_TAG)
		{
			// can't be root-level if root already closed, 
			// and can't be the only root (empty tag at depth 0 with nothing else)
			if (rootClosed) return false;
			if (depth == 0) return false;
			elementNameBag.add(token.tokenString);
		}
		else if (token.tokenType == CONTENT)
		{
			// content must be inside an element
			if (depth == 0) return false;
		}
	}

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
	if (!tokenized || !parsed) throw std::logic_error("Input not tokenized and parsed");
	return elementNameBag.contains(inputString);
}

int XMLParser::frequencyElementName(const std::string &inputString) const
{
	if (!tokenized || !parsed) throw std::logic_error("Input not tokenized and parsed");
	return elementNameBag.getFrequencyOf(inputString);
}

