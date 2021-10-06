// Project: Binary string to decimal
// File: bindary_string_to_decimal.cpp

#include <iostream>
#include <cmath>

int BinaryStringToDecimal(std::string binaryString) {
	// Initial result
	int decNumber = 0;

	// variable for current power base
	int n;

	// Declare reverse iterator
	std::string::reverse_iterator it;

	// Iterate all characters in binaryString from the last character to the first character
	for (it = binaryString.rbegin(), n = 0; it != binaryString.rend(); ++it, ++n) {
		// if character '1' is found add decNumber with power of current base
		char c = *it;
		if (c == '1') {
			decNumber += pow(2, n);
		}
	}
	// return the decimal
	return decNumber;
}

int main() {
	std::cout << "Binary String To Decimal" << std::endl;

	// Input binary string
	std::string binaryString;
	std::cout << "Input binary string -> ";
	getline(std::cin, binaryString);

	// Convert to decimal
	int decNumber = BinaryStringToDecimal(binaryString);

	// Show the result to user
	std::cout << "Decimal of '" << binaryString;
	std::cout << "' is " << decNumber << std::endl;

	return 0;
}
