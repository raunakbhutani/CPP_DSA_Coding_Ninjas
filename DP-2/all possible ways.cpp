/*
Problem statement
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.

For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-

10 = 1^2 + 3^2 
Hence, answer is 1.

Note : x^y represents x raise to the power y
*/

#include<cmath>

int countWays(int a, int b, int currentNumber){

	int currentPower = pow(currentNumber, b);

	if(currentPower == a)  // if currentPower equals 'a' we
	return 1;

	if(currentPower > a)
	return 0; 


	int includeCurrent = countWays(a - currentPower, b, currentNumber + 1);

	int excludeCurrent = countWays(a, b, currentNumber + 1);

	return includeCurrent + excludeCurrent;
}

int getAllWays(int a, int b) {
	// Write your code here

	return countWays(a, b, 1);

}
