// Project: Exponential Search
// File: exponential_search.cpp

#include <iostream>

int ExponentialSearch(int arr[], int arrSize, int val)
{
	// It's impossible to search the value in an array that contains zero or less elements
	if(arrSize <= 0)
	{
		return -1; 
	}

	// Start comparing from index 1 
	int blockIndex = 1;

	// Increase the blockIndex exponentially if blockIndex is lower than array size 
	// and the value of the element in blockIndex is still lower than the searched value 
	while(blockIndex < arrSize && arr[blockIndex] < val)
	{
		blockIndex *= 2;
	}

	// After find the blockIndex, perform Binary Search to the sub array defined by the blockIndex
	// arr[blockIndex / 2 ... blockIndex or arrSize] 
	return BinarySearch(arr, blockIndex / 2, std::min(blockIndex, arrSize), val);
}

int main()
{
	std::cout << "Exponential Search" << std::endl;

	// Initialize a new array 
	int arr[] = {8, 15, 23, 28, 32, 39, 42, 44, 47, 48};
	int arrSize = sizeof(arr)/sizeof(*arr);

	// Define the value to be searched 
	int searchedValue = 39;

	// Find the searched value using blockIndex search 
	int i = ExponentialSearch(arr, arrSize, searchedValue);

	// Notify the user the result if the return is not -1, the searched value is found 
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


