// Project: Is Subsequence
// File: is_subsequence.cpp

#include <algorithm>
#include <iostream>
#include <string>

bool IsSubsequence(std::string str1, std::string str2, int x, int y)
{
	// If all characters in str1 have been checked it menas that str1 is a subsequence of str2
	if (x == 0)
	{
		return true;
	}

	// There is some characters in str2 that don't match with str1 so return false 
	if (y == 0)
	{
		return false;
	}

	// If last characters of two strings are matching, continue to check another character 
	if (str1[x-1] == str2[y-1])
	{
		return IsSubsequence(str1, str2, x - 1, y - 1);
	}
	// If not, check the second last of str2 
	else 
	{
		return IsSubsequence(str1, str2, x, y-1);
	}
}

int main()
{
	std::cout << "Subsequence String" << std::endl;
	std::cout << "Check if 1st string is a ";
	std::cout << "subsequence of 2nd string" << std::endl;

	// Input first string 
	std::string string1;
	std::cout << "Input 1st string -> ";
	std::getline(std::cin, string1);

	// Input second string 
	std::string string2;
	std::cout << "Input 2nd string -> ";
	std::getline(std::cin, string2);

	// Check if str1 is subsequence of str2 
	std::cout << "'" << string1 << "' is ";
	if(IsSubsequence(string1, string2, string1.size(), string2.size()))
	{
		std::cout << "subsequence";
	}
	else 
	{
		std::cout << "NOT subsequence";
	}
	std::cout << " of '" << string2;
	std::cout << "'" << std::endl;

	return 0;
}
