// Project: Jump Search 
// File: jump_search.cpp

#include <iostream>

int JumpSearch(int arr[], int arrSize, int val)
{
	// It's impossible to search value if the array contains zero or less elements
	if (arrSize <= 0)
	{
		return -1;
	}

	// Defining step used to jump the array 
	int step = sqrt(arrSize);

	// Start comparing from index 0
	int blockIndex = 0;

	// Increase the blockIndex by the step if blockIndex is lower than the array size 
	// and the value of element in blockIndex is still lower than the searched value
	while (blockIndex < arrSize && arr[blockIndex] < val)
	{
		blockIndex += step;
	}

	// After find the blockIndex, perform Linear Search to the sub array 
	// defined by the blockIndex
	// arr[blockIndex - step ... blockIndex or arrSize] 
	return LinearSearch(arr, blockIndex - step, min(blockIndex, arrSize), val);
}

int main()
{
	std::cout << "Jump Search" << std::endl;

	// Initialize a new array 
	int arr[] = {8, 15, 23, 28, 32, 39, 42, 44, 47, 48};
	int arrSize = sizeof(arr)/sizeof(*arr);

	// Define the value to be searched 
	int searchedValue = 39;

	// Find the searched value using Jump Search
	int i = JumpSearch(arr, arrSize, searchedValue);

	// Notify user the result if the return is not -1, the searched value is not found 
	if(i != -1)
	{
		std::cout << searchedValue << " is found in index ";
		std::cout << i << std::endl;
	}
	else
	{
		std::cout << "Could not find value " << searchedValue;
		std::cout << std::endl;
	}

	return 0;
}

