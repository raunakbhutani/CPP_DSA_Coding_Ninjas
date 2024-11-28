/*
Problem statement
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.

Return 0 if the change isn't possible.
  */

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here

	int dp[value + 1] = {0};

	dp[0] = 1;  // base case: there is only 1 way to make change for val 0 i.e select no coins

	for(int i = 0; i < numDenominations; i++){
// for all denominations upd8 the dp array from denominations[i] to value
		for(int j = denominations[i]; j <= value; j++){
			
			dp[j] += dp[j - denominations[i]];
		}
	}

	return dp[value];
}
