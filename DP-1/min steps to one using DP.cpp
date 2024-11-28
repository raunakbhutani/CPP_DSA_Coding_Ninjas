/*
Problem statement
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
*/

#include <climits>
#include <cmath>
int countStepsToOne(int n)
{
	
	int* ans = new int[n + 1];  // array for calc ans which can be used for future use 
	
	ans[1] = 0;  // base case: it takes 0 steps to reduce 1 to 1

	 
	for(int i = 2; i <= n; i++){
		
		int x = ans[i - 1];   // step for reducing by 1

		int y = INT_MAX, z = INT_MAX;

		if(i % 2 == 0)  // if divisible by 2
		y = ans[i / 2];   // divide the no by 2

		if(i % 3 == 0)   // if divisivle by 3
		z = ans[i / 3];  // divivde the no by 3

		ans[i] = 1 + min(x, min(y, z));  // find the min steps from all the iterations
	}

	int result = ans[n];  // store the ans for future use

	delete[] ans;

	return result;
}
