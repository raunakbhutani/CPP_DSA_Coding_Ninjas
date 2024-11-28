/*
Problem statement
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Write brute-force recursive solution for this.
  */

#include <climits>
#include <cmath>
int countMinStepsToOne(int n)
{
	if(n <= 1)  // base case i.e we have reached till 1
	return 0;

	int x = countMinStepsToOne(n - 1);

	int y = INT_MAX, z = INT_MAX;  // initialise them with max val so that we don't 
	
	if(n % 2 == 0)
	y = countMinStepsToOne(n / 2);

	if(n % 3 == 0)
	z = countMinStepsToOne(n / 3);

	int ans = 1 + min(x, min(y, z));  // adding 1 bcos we subtracted 1 from n

	return ans;
}
