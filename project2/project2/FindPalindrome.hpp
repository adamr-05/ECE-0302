#ifndef FINDPALINDROME_HPP
#define FINDPALINDROME_HPP

#include <string>
#include <vector>

class FindPalindrome{

private:
	/* Define additional private members here as needed */ 
	

	/** Find and test all possible combinations of the words that have been
	 * added to the FindPalindrome instance. Must call itself recursively. 
	 * Do not change the signature of this function */
	void recursiveFindPalindromes(std::vector<std::string> candidateSentence, 
			   	                  std::vector<std::string> remainingWords);
	
	/** (Provided) Test if the input string is a palindrome.
	 * You may use or modify this function. Note: you probably 
	 * do not want to use a recursive version of this as it is 
	 * inefficient. You may change the signature of this function. */
	bool isPalindrome(std::string testString) const;
	
public:
	/** Constructor for the FindPalindrome object. */
	FindPalindrome();

	/** Destroys object and frees any memory allocated by object. */
	~FindPalindrome();

	/** Returns the current number of sentence palindromes in the
	 * FindPalindrome instance.
	 * @return The integer number of palindromes in the instance. */
	int number() const;

	/** Removes all words from this instance. The internal list
	 * of sentence palindromes is cleared and any internal data
	 * structures are reset.
	 * @post The instance contains no words, and the number of
	 * sentence palindromes is 0. */
	 void clear();
	 
	/** Adds a new string (word) to this FindPalindrome instance and recomputes the
	 * palindrome sentences possible with the current word list. The new word must be valid
	 * and unique according to the project description.
	 * @param newWord  The string to add to the instance of FindPalindrome.
	 * @return True if addition was successful, or false if not. 
	 * @post If successful, the string has been added to the FindPalindrome
	 * instance, and the number and list of sentence palindromes in the instance 
	 * have been recomputed. */
	bool add(const std::string & newWord);
	
	/** Adds a new vector of strings (words) to this FindPalindrome instance and
	 * recomputes the palindrome sentences possible with the current word list. 
	 * DO NOT implement this method by repeatedly calling the add(string) method 
	 * as this would be very inefficient. Each string in the vector must be valid and 
	 * unique according to the project description. If any word in the vector is invalid,
	 * the add fails and NONE OF THE WORDS from the vector should be added.
	 * @param wordVector  The vector of strings to add to the instance of
	 * FindPalindrome.
	 * @return True if addition was successful, or false if not. 
	 * @post If successful, the vector of strings has been added to the 
	 * FindPalindrome instance, and the sentence palindromes for the instance 
	 * have been recomputed. */
	bool add(const std::vector<std::string> & wordVector);
	
	/** Test if a palindrome is possible, if not, no need to go any 
	 * further. See the project description for how this method is to be implemented and used.
	 * @param wordVector A vector of strings (words) for which we want to 
	 * test to see if they could be reordered to form a sentence palindrome.
	 * @return True if a palindrome is possible, false otherwise. */
	bool cutTest1(const std::vector<std::string> & wordVector);

	/** Test if a palindrome is possible, if not, no need to go any 
	 * further. See the project description for how this method is to be implemented and used.
	 * Either string vector could be the shorter string in the test, so do not assume one is 
	 * always shorter. The count of characters should be case insensitive.	   
	 * @param wordVector1 First vector of strings (words).
	 * @param wordVector2 Second vector of strings (words). 
	 * @return True if a palindrome is possible, false otherwise. */
	bool cutTest2(const std::vector<std::string> & wordVector1, 
			      const std::vector<std::string> & wordVector2);

	/** Returns the list of palindrome sentences for the current list of words.
	 * Note this method is const, so nothing should be recomputed here, just returned. 
	 * @return A vector of vectors containing all palindrome sentences. */
	std::vector< std::vector<std::string> > toVector() const;
};

#endif
