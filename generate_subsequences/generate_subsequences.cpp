// Project: Generate Subsequences
// File: generate_subsequences.cpp

#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>

std::vector<std::string> GenerateSubsequences(std::string str)
{
	// Return value is stored on vecString
	std::vector<std::string> vecString;

	// Retrieve str length
	int strLen = str.size();

	// bitCounter is used to check character position 
	int bitCounter = std::pow(2, strLen);
	std::cout << bitCounter << std::endl;

	// Check from 000...001 to 111..111 
	// Empty subset is ignored 
	for (int i=1; i < bitCounter; ++i)
	{
		// Temporary variable to store current subsequence 
		std::string subsequence = "";

		// Construct the new subsequence string 
		for (int j=0; j < strLen; j++)
		{
			// Check if j-th bit in the bitCounter is set
			// If so, pick j-th character from str 
			if (i & (1 << j))
			{
				subsequence += str[j];
			}
		}

		// Put it to vector 
		vecString.push_back(subsequence);

	}

	// Return the vector 
	return vecString;
}	

int main()
{
	std::cout << "Subsequence Generator" << std::endl;

	// Input string 
	std::string str;
	std::cout << "Input string -> ";
	std::getline(std::cin, str);

	// Generate subsequences
	std::vector<std::string> myvector = GenerateSubsequences(str);

	// Show the result to the user 
	std::cout << "All subsequences of '" << str;
	std::cout << "':" << std::endl;
	for ( std::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << myvector.size() << " " << myvector.capacity() << std::endl;

	return 0;
}

