// Project: Search Pattern
// File: search_pattern.cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<int> SearchPattern(std::string targetString, std::string patternString)
{
	std::vector<int> vecIndex;

	// Retrieve string length 
	int strLen = targetString.size();
	int patLen = patternString.size();

	// Only perform the following procedure if pattern string is not longer than target string 
	if(patLen <= strLen)
	{
		// Iterate through target string elements from the beginning until the last possible 
		// element where pattern is at the last position 
		for(int i=0; i <= strLen - patLen; ++i)
		{
			int j;

			// Start comparing pattern string 
			for(j=0; j < patLen; ++j)
			{
				// Quit from inner for-loop if character is not matched
				if(targetString[i+j] != patternString[j])
				{
					break;
				}
			}

			// If inner for-loop is done it means that pattern is found in the target string 
			if(j == patLen)
			{
				// store the index in vector 
				vecIndex.push_back(i);
			}
		}
	}

	// Return the vector 
	return vecIndex;
}

int main()
{
	std::cout << "Pattern Searching" << std::endl;
	
	// Input target string 
	std::string targetStr;
	std::cout << "Input target string -> ";
	std::getline(std::cin, targetStr);

	// Input pattern string 
	std::string patternStr;
	std::cout << "Input pattern string -> ";
	std::getline(std::cin, patternStr);

	// Find the pattern 
	std::vector<int> myvector = SearchPattern(targetStr, patternStr);

	// Show the result to user 
	std::cout << "'" << patternStr << "' is ";
	if(myvector.size() > 0)
	{
		std::cout << "found at index ";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		{
			std::cout << *it << " ";
		}
	}
	else 
	{
		std::cout << "Not found";
	}
	std::cout << std::endl;

	return 0;

}

