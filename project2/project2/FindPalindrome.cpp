#include <string>
#include <vector>
#include "FindPalindrome.hpp"
#include <cctype>


//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

/** Helper function to convert string to lower case */
static void convertToLowerCase(std::string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

void FindPalindrome::recursiveFindPalindromes(std::vector<std::string>
        candidateSentence, std::vector<std::string> remainingWords)
{
	//if no remaining words, check palindrome & return & update data
	if (remainingWords.empty())
	{
		std::string palindromeTest;
		for (int i = 0; i < candidateSentence.size(); i++)
		{
			for (int j = 0; j < candidateSentence[i].size(); j++)
			{
				palindromeTest.push_back(candidateSentence[i][j]);
			}
		}
		if (isPalindrome(palindromeTest))
		{
			palindromes.push_back(candidateSentence);
		}
		return;
	}
	

	for (int i = 0; i < remainingWords.size(); i++)
	{
		// add ith word to candidate
		candidateSentence.push_back(remainingWords[i]);
		
		//change remainingwords var to remove ith word
		std::vector<std::string> newRemainingWords;
		for (int j = 0; j < remainingWords.size(); j++)
		{
			if (j != i)
			newRemainingWords.push_back(remainingWords[j]);
		}

		//recursively call with new candidate and remainingwords
		recursiveFindPalindromes(candidateSentence,newRemainingWords);

		//remove tried element in pos. to try i+1th element instead on next call
		candidateSentence.pop_back();
	}
}

bool FindPalindrome::isPalindrome(std::string testString) const
{
	// make sure that the string is lower case
	convertToLowerCase(testString);
	// see if the characters are symmetric
	int stringLength = testString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (testString[i] != testString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{}

FindPalindrome::~FindPalindrome()
{}

int FindPalindrome::number() const
{
	return palindromes.size(); // return SIZE of palindromes vector, which is number of palindromes found
}

void FindPalindrome::clear()
{
	vectorOfStrings.clear(); //clear palindromes list
	palindromes.clear();	//clear data
}

bool FindPalindrome::cutTest1(const std::vector<std::string> & wordVector)
{
	// TODO 
	return false;
}

bool FindPalindrome::cutTest2(const std::vector<std::string> & wordVector1,
                              const std::vector<std::string> & wordVector2)
{
	// TODO 
	return false;
}

bool FindPalindrome::add(const std::string & newWord)
{
	bool validWord = true;

	// Check if word being added is unique
	for (int i = 0; i < vectorOfStrings.size(); i++)
	{
		if (vectorOfStrings[i] == newWord)
		{
			validWord = false; //if not unique, not valid
			break;
		}
	}

	//check if word being added contains only alphabetic characters
	if (validWord)
	{
		for (int i = 0; i < newWord.size(); i++)
		{
			if (!isalpha(newWord[i]))
			{
				validWord = false;
				break;
			}
		}
	}

	if (validWord)
	{
		vectorOfStrings.push_back(newWord);				//here i used testing cases to figure out it wasnt updating when i used add function. need to call recursive from here
		palindromes.clear();
		std::vector<std::string> empty; //empty string to use to call
		recursiveFindPalindromes(empty, vectorOfStrings);
	}	
	return validWord;
}

bool FindPalindrome::add(const std::vector<std::string> & wordVector)
{
	// TODO 
	return false;
}

std::vector< std::vector<std::string> > FindPalindrome::toVector() const
{
	// TODO
	return std::vector< std::vector<std::string> >();
}

