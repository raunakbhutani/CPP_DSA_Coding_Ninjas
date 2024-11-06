/*
Problem statement
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.



Note:
Array A can contain duplicate elements as well.
  */

#include <unordered_map>

int pairSum(int *arr, int n) {
	// Write your code here
	
	unordered_map<int, int> frequencyMap;  // map to store the elem with their freq

	int count = 0;  // store the freq of complement

// store the freq of each elem in the array
	for(int i=0; i<n; i++){
		frequencyMap[arr[i]]++;
	}

// count the pairs which sum to 0
	for(int i=0; i<n; i++){
		int complement = -arr[i];

		if(frequencyMap.find(complement) != frequencyMap.end())  // if there exists a complement 
		count += frequencyMap[complement];  // then add that in count

		if(arr[i] == complement)  // avoid checking for pairs like (0, 0)
		count--;
	}
	
	return count / 2;  // as each elem is counted twice
}
