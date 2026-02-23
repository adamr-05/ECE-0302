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
	// if palindrome even, every character must appear even number of times
	// if palindrome odd, character in center appears odd num of times, all others even num of times

	std::string sentence;
	for (int i = 0; i < wordVector.size(); i++)
	{
		sentence+= (wordVector[i]);
	}
	convertToLowerCase(sentence);

	int letterArray[26] = {0};
	for (int i = 0; i < sentence.size(); i++)
	{
		int letterIndex = sentence[i] - 'a'; // find ith element, then find its char and subtract a, giving ints 1 (a) through 26 (z).
		letterArray[letterIndex]++; //increment letter count
	}

	int oddCount = 0;
	for (int i = 0; i < 26; i ++)
	{
		if (letterArray[i] % 2 != 0) // 1 if odd, 0 if even
		{
			oddCount++; //increase number of odd nums
		}
	}
	//if even length, number of odd chars cannot be ODD, only even, so we can use <= 1.

	return oddCount <= 1; // if the number off odd numbers is greater than one, than it logically cannot be a palindrome whether even or odd
}

bool FindPalindrome::cutTest2(const std::vector<std::string> & wordVector1,
                              const std::vector<std::string> & wordVector2)
{

	//create 2 strings based on wordVector1 and wordVector2 data
	std::string string1, string2;
	for (int i = 0; i < wordVector1.size(); i++)
	string1 += wordVector1[i];

	for (int i = 0; i < wordVector2.size(); i++)
	string2 += wordVector2[i];
	
	//convert them to lowercase to test
	convertToLowerCase(string1);
	convertToLowerCase(string2);

	//find smaller and larger string
	std::string smaller, larger;
	if (string1.size() <= string2.size())
	{
		smaller = string1;
		larger = string2;
	}
	else
	{
		smaller = string2;
		larger = string1;
	}

	//create 2 more arrays to count frequency of each letter in each string
	int smallerArrayLetterFreq[26] = {0};
	int largerArrayLetterFreq[26] = {0};

	//count frequency of each
	for (int i = 0; i < smaller.size(); i++)
	{
		int letterIndex = smaller[i] - 'a'; // find ith element, then find its char and subtract a, giving ints 1 (a) through 26 (z).
		smallerArrayLetterFreq[letterIndex]++; //increment letter count
	}
	for (int i = 0; i < larger.size(); i++)
	{
		int letterIndex = larger[i] - 'a'; // find ith element, then find its char and subtract a, giving ints 1 (a) through 26 (z).
		largerArrayLetterFreq[letterIndex]++; //increment letter count
	}

	//now compare frequencies, frequency of all letters in larger should be greater than any in smaller
	for (int i = 0; i < 26; i++)
	{
		if (smallerArrayLetterFreq[i] > largerArrayLetterFreq[i])
		return false;
	}
	return true;

}

bool FindPalindrome::add(const std::string & newWord)
{																//OVERCAME PROBLEM HERE
	if (newWord.empty()) return false;					//here i used testing cases to verify add didn't work with empty string which was an easy fix
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
	{																//OVERCAME PROBLEM HERE
		vectorOfStrings.push_back(newWord);				//here i used testing cases to figure out it wasnt updating when i used add function. need to call recursive from here
		palindromes.clear();
		std::vector<std::string> empty; //empty string to use to call
		recursiveFindPalindromes(empty, vectorOfStrings);
	}	
	return validWord;
}

bool FindPalindrome::add(const std::vector<std::string> & wordVector)
{

	bool validVector = true;

	//loop through vector
	for (int i = 0; i < wordVector.size(); i++)
	{
		//check alpha chars of string
		for (int j = 0; j < wordVector[i].size(); j++)
		{
			if (!isalpha(wordVector[i][j]))
			{
				validVector = false;
			}
		}

		//check uniqueness against itself
		for (int j = i+1; j < wordVector.size(); j++) // j is vector element after i, so compares i term to i+N terms, which should cover all terms
		{
			if (wordVector[i]==wordVector[j])
			{
				validVector = false;
			}
		}

		//check uniqueness against existing vector
		for (int j = 0; j < vectorOfStrings.size(); j++)
		{
			if (vectorOfStrings[j] == wordVector[i])
			{
				validVector = false;
			}
		}
	}

	//if invalid return false
	if (validVector == false) return false;


	// append all valid elements to existing vectorOfStrings
	for (int i = 0; i < wordVector.size(); i++)
	{
		vectorOfStrings.push_back(wordVector[i]);
	}

	//clear data and recursively find palindromes
	palindromes.clear();
	std::vector<std::string> empty;
	recursiveFindPalindromes(empty, vectorOfStrings);
	return true;
}

std::vector< std::vector<std::string> > FindPalindrome::toVector() const
{
	return palindromes;
}

