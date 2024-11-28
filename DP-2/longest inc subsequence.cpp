/*
Problem statement
Given an array with N elements, you need to find the length of the longest subsequence in the given array
such that all elements of the subsequence are sorted in strictly increasing order.
  */

int longestIncreasingSubsequence(int *arr, int n) {
  // Write your code here

 
  int *output = new int[n]; // array to store the len of LIS upto idx i

  output[0] = 1; // when there is only 1 elem then LIS = 1

  for (int i = 1; i < n; i++) {
    output[i] = 1;
    for (int j = i - 1; j >= 0; j--) { // start traversing from n - 1

      if (arr[j] >= arr[i]) // if we encounter a larger or equal elem before smaller elem
        continue;          // then no point considering it in LIS

      int possibleAns = output[j] + 1;
      if (possibleAns > output[i])
        output[i] = possibleAns;
    }
  }

	int bestAns = 0;  // to calc the LIS

	for(int i = 0; i < n; i++){

		if(bestAns < output[i])
		bestAns = output[i];
	}

  delete[] output;

  return bestAns;
}
