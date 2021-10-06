// Project: Palindrome
// File: palindrome.cpp

#include <iostream>
#include <string>

bool IsPalindrome(std::string str)
{
	// Palindrome is not case sensitive so we convert all chars to uppercase
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);

	// Palindrome does not case about space so we remove all spaces if any 
	str.erase(remove(str.begin(), str.end(), ' '), str.end());

	// --- Palindrome Detetector ---
	// Starting from the leftmost and rightmost elements of the str 
	int left = 0;
	int right = str.length() - 1;

	// Comparing the current leftmost and rightmost elements until all elements are checked or until
	// unmatched characters are found
	while(right > left)
	{
		if(str[left++] != str[right--])
		{
			return false;
		}
	}

	// If all characters which are compared are the same, it must be a palindrome
	return true;
	
	// --- End of palindrome detector ---
}

int main()
{
	std::cout << "Palindrome" << std::endl;

	// Input string
	std::string str;
	std::cout << "Input string -> ";
	std::getline(std::cin, str);

	// Check if it is a palindrome
	std::cout << "'" << str << "' is ";
	if(IsPalindrome(str))
	{
		std::cout << "a palindrome";
	}
	else
	{
		std::cout << "NOT a palindrome";
	}
	std::cout << std::endl;

	return 0;
}

