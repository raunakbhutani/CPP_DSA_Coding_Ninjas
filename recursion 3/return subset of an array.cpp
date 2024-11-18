/*
Problem statement
Given an integer array (of length n), find and return all the subsets of input array.

NOTE- Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note :
The order of subsets are not important.
  */

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don?t print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20]) {
    // Write your code here
// output array in which each row repr a subset & size of each subset is assumed to be 20

	if(n == 0){    // base case: empty subset
		output[0][0] = 0;  
		return 1;
	}

	int smallOutputSize = subset(input + 1, n-1, output);  // get subsets of remaining elem

	for(int i = 0; i < smallOutputSize; i++){  // now add the first elem to each subset gen during the recursive call

		int subsetSize = output[i][0];  // retrieves the size of current subset

		output[i + smallOutputSize][0] = subsetSize + 1;  // size of new subset by adding input[0]
	
		output[i + smallOutputSize][1] = input[0];  // add the first elem

		for(int j = 1; j <= subsetSize; j++){
// the existing elements of the subset are copied to the new subset, starting from the position after input[0].
			output[i + smallOutputSize][j + 1] = output[i][j];
		}
	}
	return 2 * smallOutputSize;
}
