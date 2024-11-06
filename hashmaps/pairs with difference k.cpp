/*
Problem statement
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.

Note: Take absolute difference between the elements of the array.
  */

#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here

	unordered_map<int, int> freqMap;  // store the freq of each elem as u iter8 through it
	int pairCount = 0;  	// no of pairs with diff = k

    for (int i = 0; i < n; i++) {

        int curr_elem = arr[i];

// check for complement
        int complement1 = curr_elem + k;  
        int complement2 = curr_elem - k;


		if(freqMap.find(complement1) != freqMap.end())  // if comp1 exists 
		pairCount += freqMap[complement1];  // add that to pair count

		if(k!=0 && freqMap.find(complement2) != freqMap.end())  // if comp2 exists
		pairCount += freqMap[complement2];  // add that to pair count

		freqMap[curr_elem]++;  // upd8 the freq map with current elem
    }
        return pairCount;
}
