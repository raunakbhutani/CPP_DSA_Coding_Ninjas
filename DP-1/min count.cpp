/*
Problem statement
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.

That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}.
  The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
  */

#include<climits>
int minCount(int n)
{
	
	int* arr = new int[n + 1];
	
	arr[0] = 0;  // base case: 0 can be rep by 0 squares

	
	for(int i = 1; i <= n; i++){
		arr[i] = INT_MAX;
		
        for (int j = 1; j * j <= i; j++) {

            arr[i] = min(arr[i], arr[i - j * j] + 1);  // arr[i - j * j] represents the minimum number of squares required to sum up to i - j * j, and by adding one more square (j * j),
          }
     }
	 int result = arr[n];

	 delete[] arr;

	 return result;
}
  
