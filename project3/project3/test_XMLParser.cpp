#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

#include "catch.hpp"
#include "XMLParser.hpp"

/* Provided test cases */
TEST_CASE("XMLParser: Test int Stack push and size", "[Stack]")
{
	Stack<int> intStack;
	int testSize = 3;
	int stackSize;
	bool correctPush, correctSize;
	for (int i = 0; i < testSize; i++)
	{
		correctPush = intStack.push(i);
		stackSize = intStack.size();
		correctSize = (stackSize == (i + 1));
		if (!correctPush || !correctSize)
		{
			break;
		}
	}
	REQUIRE(correctPush);
	REQUIRE(correctSize);
}

TEST_CASE("XMLParser: Test int Stack peek, pop", "[Stack]")
{
	Stack<int> intStack;
	int testSize = 10;
	int stackSize;
	bool correctSizeAfterPush;
	for (int i = 0; i < testSize; i++)
	{
		intStack.push(i);
		stackSize = intStack.size();
		correctSizeAfterPush = (stackSize == (i + 1));
		if (!correctSizeAfterPush)
		{
			break;
		}
	}
	REQUIRE(correctSizeAfterPush);
	bool notEmptyYetAfterPop, correctItem, notEmptyYetAfterPeek;
	for (int i = testSize - 1; i >= 0; i--)
	{
		notEmptyYetAfterPop = !intStack.isEmpty();
		int elem = intStack.peek();
		correctItem = (elem == i);
		notEmptyYetAfterPeek = !intStack.isEmpty();
		intStack.pop();
		if (!notEmptyYetAfterPop || !correctItem || !notEmptyYetAfterPeek)
		{
			break;
		}
	}
	REQUIRE(notEmptyYetAfterPop);
	REQUIRE(correctItem);
	REQUIRE(notEmptyYetAfterPeek);
	REQUIRE(intStack.isEmpty() == true);
}


TEST_CASE("XMLParser: Test tokenize <test>stuff</test>", "[XMLParser]")
{
	// You can assume that the beginning and the end of CONTENT will not be filled with whitespace
	XMLParser myXMLParser;
	std::string testString = "<test>stuff</test>";
	REQUIRE(myXMLParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("test")},
									   TokenStruct{StringTokenType::CONTENT, std::string("stuff")},
									   TokenStruct{StringTokenType::END_TAG, std::string("test")}};
	std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
	bool correctType, correctString;
	for (int i = 0; i < result.size(); i++)
	{
		correctType = (result[i].tokenType == output[i].tokenType);
		correctString = (result[i].tokenString.compare(output[i].tokenString) == 0);
		if (!correctType || !correctString) {
			break;
		}
	}
	REQUIRE(correctType);
	REQUIRE(correctString);
}


TEST_CASE("XMLParser: Test tokenize more elements", "[XMLParser]")
{
	XMLParser myXMLParser;
	std::string testString = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><Note src='gmail'>  <From>Tom</From> <To>Alice</To> </Note>";
	REQUIRE(myXMLParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::DECLARATION, std::string("xml version=\"1.0\" encoding=\"UTF-8\"")},
									   TokenStruct{StringTokenType::START_TAG, std::string("Note")},
									   TokenStruct{StringTokenType::START_TAG, std::string("From")},
									   TokenStruct{StringTokenType::CONTENT, std::string("Tom")},
									   TokenStruct{StringTokenType::END_TAG, std::string("From")},
									   TokenStruct{StringTokenType::START_TAG, std::string("To")},
									   TokenStruct{StringTokenType::CONTENT, std::string("Alice")},
									   TokenStruct{StringTokenType::END_TAG, std::string("To")},
									   TokenStruct{StringTokenType::END_TAG, std::string("Note")}};
	std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();

	REQUIRE(result.size() == output.size());
	bool correctType, correctString;
	for (int i = 0; i < result.size(); i++)
	{
		correctType = (result[i].tokenType == output[i].tokenType);
		correctString = (result[i].tokenString.compare(output[i].tokenString) == 0);
		if (!correctType || !correctString) {
			break;
		}
	}
	REQUIRE(correctType);
	REQUIRE(correctString);
}

TEST_CASE("XMLParser: Test parseTokenizedInput", "[XMLParser]")
{
	XMLParser myXMLParser;
	std::string testString = "<test myattr='abcdef'>stuff<this_is_empty_tag/></test>";
	REQUIRE(myXMLParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("test")},
									   TokenStruct{StringTokenType::CONTENT, std::string("stuff")},
									   TokenStruct{StringTokenType::EMPTY_TAG, std::string("this_is_empty_tag")},
									   TokenStruct{StringTokenType::END_TAG, std::string("test")}};
	std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
	REQUIRE(myXMLParser.parseTokenizedInput());
	output = myXMLParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
	bool correctType, correctString;
	for (int i = 0; i < result.size(); i++)
	{
		correctType = (result[i].tokenType == output[i].tokenType);
		correctString = (result[i].tokenString.compare(output[i].tokenString) == 0);
		if (!correctType || !correctString) {
			break;
		}
	}
	REQUIRE(correctType);
	REQUIRE(correctString);
}


TEST_CASE("XMLParser: Test XMLParser parse, contains and frequency", "[XMLParser]")
{
	XMLParser myXMLParser;
	std::ifstream myfile("../TestFile.txt");
	std::string inputString((std::istreambuf_iterator<char>(myfile)), (std::istreambuf_iterator<char>()));

	REQUIRE(myXMLParser.tokenizeInputString(inputString));
	REQUIRE(myXMLParser.parseTokenizedInput());
	REQUIRE(myXMLParser.containsElementName("catalog"));
	REQUIRE(myXMLParser.frequencyElementName("catalog") == 1);
	REQUIRE(myXMLParser.containsElementName("product"));
	REQUIRE(myXMLParser.frequencyElementName("product") == 1);
	REQUIRE(myXMLParser.containsElementName("catalog_item"));
	REQUIRE(myXMLParser.frequencyElementName("catalog_item") == 2);
	REQUIRE(myXMLParser.containsElementName("item_number"));
	REQUIRE(myXMLParser.frequencyElementName("item_number") == 2);
	REQUIRE(myXMLParser.containsElementName("size"));
	REQUIRE(myXMLParser.frequencyElementName("size") == 6);
	REQUIRE(myXMLParser.containsElementName("color_swatch"));
	REQUIRE(myXMLParser.frequencyElementName("color_swatch") == 15);
}

/* Your test cases here */

/* Stack tests */
TEST_CASE("Stack: Test empty stack", "[Stack]")
{
	Stack<int> s;
	REQUIRE(s.isEmpty());
	REQUIRE(s.size() == 0);
	REQUIRE(s.pop() == false);
	REQUIRE_THROWS_AS(s.peek(), std::logic_error);
}

TEST_CASE("Stack: Test clear", "[Stack]")
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.clear();
	REQUIRE(s.isEmpty());
	REQUIRE(s.size() == 0);
}

TEST_CASE("Stack: Test string stack", "[Stack]")
{
	Stack<std::string> s;
	s.push("hello");
	s.push("world");
	REQUIRE(s.peek() == "world");
	s.pop();
	REQUIRE(s.peek() == "hello");
}

/* Tokenizer fail cases */
TEST_CASE("XMLParser: Tokenize empty string", "[XMLParser]")
{
	XMLParser p;
	REQUIRE_FALSE(p.tokenizeInputString(""));
}

TEST_CASE("XMLParser: Tokenize whitespace only", "[XMLParser]")
{
	XMLParser p;
	REQUIRE_FALSE(p.tokenizeInputString("   \n\t  "));
}

TEST_CASE("XMLParser: Tokenize empty brackets", "[XMLParser]")
{
	XMLParser p;
	REQUIRE_FALSE(p.tokenizeInputString("<>"));
}

TEST_CASE("XMLParser: Tokenize unclosed bracket", "[XMLParser]")
{
	XMLParser p;
	REQUIRE_FALSE(p.tokenizeInputString("<start"));
}

TEST_CASE("XMLParser: Tokenize nested brackets", "[XMLParser]")
{
	XMLParser p;
	REQUIRE_FALSE(p.tokenizeInputString("<start <stuff>>"));
}

TEST_CASE("XMLParser: Tokenize invalid tag name starting with number", "[XMLParser]")
{
	XMLParser p;
	REQUIRE_FALSE(p.tokenizeInputString("<1bad></1bad>"));
}

TEST_CASE("XMLParser: Tokenize space after open bracket", "[XMLParser]")
{
	XMLParser p;
	REQUIRE_FALSE(p.tokenizeInputString("< /end>"));
}

TEST_CASE("XMLParser: Tokenize lone close bracket", "[XMLParser]")
{
	XMLParser p;
	REQUIRE_FALSE(p.tokenizeInputString(" >"));
}

TEST_CASE("XMLParser: Tokenize invalid end tag with slash", "[XMLParser]")
{
	XMLParser p;
	REQUIRE_FALSE(p.tokenizeInputString("<test>stuff</test/>"));
}

TEST_CASE("XMLParser: Tokenize stray close bracket between tags", "[XMLParser]")
{
	XMLParser p;
	REQUIRE_FALSE(p.tokenizeInputString("<a>stuff>more</a>"));
}

/* Tokenizer success cases */
TEST_CASE("XMLParser: Tokenize only declaration", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<?xml version=\"1.0\"?>"));
}

TEST_CASE("XMLParser: Tokenize empty tag", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<br/>"));
}

TEST_CASE("XMLParser: Tokenize empty tag with attributes", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<img src=\"test.jpg\"/>"));
	std::vector<TokenStruct> output = p.returnTokenizedInput();
	REQUIRE(output.size() == 1);
	REQUIRE(output[0].tokenType == EMPTY_TAG);
	REQUIRE(output[0].tokenString == "img");
}

TEST_CASE("XMLParser: Tokenize start tag with attributes", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<Edgar src=\"edgar.jpg\" version=\"1.0\"></Edgar>"));
	std::vector<TokenStruct> output = p.returnTokenizedInput();
	REQUIRE(output[0].tokenType == START_TAG);
	REQUIRE(output[0].tokenString == "Edgar");
}

TEST_CASE("XMLParser: Tokenize tag name with valid special chars", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<my-tag.name></my-tag.name>"));
	std::vector<TokenStruct> output = p.returnTokenizedInput();
	REQUIRE(output[0].tokenString == "my-tag.name");
}

TEST_CASE("XMLParser: Tokenize tag name starting with underscore", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<_private></_private>"));
	std::vector<TokenStruct> output = p.returnTokenizedInput();
	REQUIRE(output[0].tokenString == "_private");
}

TEST_CASE("XMLParser: Tokenize clears previous data", "[XMLParser]")
{
	XMLParser p;
	p.tokenizeInputString("<a></a>");
	p.tokenizeInputString("<b></b>");
	std::vector<TokenStruct> output = p.returnTokenizedInput();
	REQUIRE(output.size() == 2);
	REQUIRE(output[0].tokenString == "b");
}

/* Parse fail cases */
TEST_CASE("XMLParser: Parse mismatched tags", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<a></b>"));
	REQUIRE_FALSE(p.parseTokenizedInput());
}

TEST_CASE("XMLParser: Parse unmatched start tag", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<onetag>"));
	REQUIRE_FALSE(p.parseTokenizedInput());
}

TEST_CASE("XMLParser: Parse reversed tags", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("</test>stuff<test>"));
	REQUIRE_FALSE(p.parseTokenizedInput());
}

TEST_CASE("XMLParser: Parse multiple root elements", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<root></root><other></other>"));
	REQUIRE_FALSE(p.parseTokenizedInput());
}

TEST_CASE("XMLParser: Parse content only no tags", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("just some content"));
	REQUIRE_FALSE(p.parseTokenizedInput());
}

TEST_CASE("XMLParser: Parse empty tag as root", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<br/>"));
	REQUIRE_FALSE(p.parseTokenizedInput());
}

TEST_CASE("XMLParser: Parse declaration after root opens", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<root><?xml version=\"1.0\"?></root>"));
	REQUIRE_FALSE(p.parseTokenizedInput());
}

TEST_CASE("XMLParser: Parse incorrectly nested tags", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<a><b></a></b>"));
	REQUIRE_FALSE(p.parseTokenizedInput());
}

/* Parse success cases */
TEST_CASE("XMLParser: Parse simple valid XML", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<test>stuff</test>"));
	REQUIRE(p.parseTokenizedInput());
}

TEST_CASE("XMLParser: Parse nested elements", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<a><b><c></c></b></a>"));
	REQUIRE(p.parseTokenizedInput());
}

TEST_CASE("XMLParser: Parse with declaration before root", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<?xml version=\"1.0\"?><root></root>"));
	REQUIRE(p.parseTokenizedInput());
}

TEST_CASE("XMLParser: Parse with empty tag inside root", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<root><br/></root>"));
	REQUIRE(p.parseTokenizedInput());
}

TEST_CASE("XMLParser: Parse content mixed with child elements", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<root>text<child>more</child>end</root>"));
	REQUIRE(p.parseTokenizedInput());
}

TEST_CASE("XMLParser: Parse multiple declarations before root", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<?xml version=\"1.0\"?><?doctype stuff?><root></root>"));
	REQUIRE(p.parseTokenizedInput());
}

/* Element name tests */
TEST_CASE("XMLParser: Element name frequency with duplicates", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<root><item></item><item></item></root>"));
	REQUIRE(p.parseTokenizedInput());
	REQUIRE(p.containsElementName("root"));
	REQUIRE(p.containsElementName("item"));
	REQUIRE(p.frequencyElementName("root") == 1);
	REQUIRE(p.frequencyElementName("item") == 2);
	REQUIRE_FALSE(p.containsElementName("missing"));
	REQUIRE(p.frequencyElementName("missing") == 0);
}

TEST_CASE("XMLParser: Element name includes empty tags", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<root><br/><br/><br/></root>"));
	REQUIRE(p.parseTokenizedInput());
	REQUIRE(p.containsElementName("br"));
	REQUIRE(p.frequencyElementName("br") == 3);
}

TEST_CASE("XMLParser: Element name case sensitive", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<Root><root></root></Root>"));
	REQUIRE(p.parseTokenizedInput());
	REQUIRE(p.containsElementName("Root"));
	REQUIRE(p.containsElementName("root"));
	REQUIRE(p.frequencyElementName("Root") == 1);
	REQUIRE(p.frequencyElementName("root") == 1);
}

TEST_CASE("XMLParser: Element name throws before tokenize and parse", "[XMLParser]")
{
	XMLParser p;
	REQUIRE_THROWS_AS(p.containsElementName("test"), std::logic_error);
	REQUIRE_THROWS_AS(p.frequencyElementName("test"), std::logic_error);
}

TEST_CASE("XMLParser: Element name throws after tokenize but before parse", "[XMLParser]")
{
	XMLParser p;
	p.tokenizeInputString("<test></test>");
	REQUIRE_THROWS_AS(p.containsElementName("test"), std::logic_error);
}

TEST_CASE("XMLParser: Clear resets state for element name queries", "[XMLParser]")
{
	XMLParser p;
	REQUIRE(p.tokenizeInputString("<a></a>"));
	REQUIRE(p.parseTokenizedInput());
	REQUIRE(p.containsElementName("a"));
	p.clear();
	REQUIRE_THROWS_AS(p.containsElementName("a"), std::logic_error);
}

TEST_CASE("XMLParser: Checkoff example", "[XMLParser]") {
    XMLParser p;
    std::string input = "<?xml version=\"1.0\"?><library><book>Title A</book><book>Title B</book><br/></library>";

    // 1. tokenize
    REQUIRE(p.tokenizeInputString(input));

    // 2. check tokens
    // tokens are: DECLARATION, START library, START book, CONTENT "Title A",
    //             END book, START book, CONTENT "Title B", END book,
    //             EMPTY br, END library
    std::vector<TokenStruct> output = p.returnTokenizedInput();
    REQUIRE(output.size() == 10);

    REQUIRE(output[0].tokenType == DECLARATION);
    REQUIRE(output[0].tokenString == "xml version=\"1.0\"");

    REQUIRE(output[1].tokenType == START_TAG);
    REQUIRE(output[1].tokenString == "library");

    REQUIRE(output[2].tokenType == START_TAG);
    REQUIRE(output[2].tokenString == "book");

    REQUIRE(output[3].tokenType == CONTENT);
    REQUIRE(output[3].tokenString == "Title A");

    REQUIRE(output[4].tokenType == END_TAG);
    REQUIRE(output[4].tokenString == "book");

    REQUIRE(output[5].tokenType == START_TAG);
    REQUIRE(output[5].tokenString == "book");

    REQUIRE(output[6].tokenType == CONTENT);
    REQUIRE(output[6].tokenString == "Title B");

    REQUIRE(output[7].tokenType == END_TAG);
    REQUIRE(output[7].tokenString == "book");

    REQUIRE(output[8].tokenType == EMPTY_TAG);
    REQUIRE(output[8].tokenString == "br");

    REQUIRE(output[9].tokenType == END_TAG);
    REQUIRE(output[9].tokenString == "library");

    // 3. parse
    REQUIRE(p.parseTokenizedInput());

    // 4. element names (only START_TAG and EMPTY_TAG count)
    REQUIRE(p.containsElementName("library"));
    REQUIRE(p.frequencyElementName("library") == 1);
    REQUIRE(p.containsElementName("book"));
    REQUIRE(p.frequencyElementName("book") == 2);
    REQUIRE(p.containsElementName("br"));
    REQUIRE(p.frequencyElementName("br") == 1);
    REQUIRE_FALSE(p.containsElementName("xml"));  // declaration doesn't count
}


TEST_CASE("XML Parser", "[XML Parser]")
{
	XMLParser p;
	std::string testInput = "<a>hi</a>";

	REQUIRE(p.tokenizeInputString(testInput));


	REQUIRE(p.parseTokenizedInput());
}
