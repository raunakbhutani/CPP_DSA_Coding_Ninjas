/*
Problem statement
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first.
In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
  */

#include<vector>
string findWinner(int n, int x, int y)
{
	// Write your code here .

	vector<bool> dp(n + 1, false); 

	dp[0] = false;  // base case: the current player loses bcos no coins are left

	for(int i = 1; i <= n; i++){

// check if by removing 1, i - x or i - y can make the opponent lose

		if(i - 1 >= 0 && !dp[i - 1])
		dp[i] = true;

		else if(i - x >= 0 && !dp[i - x])
		dp[i] = true;

		else if(i - y >= 0 && !dp[i - y])
		dp[i] = true;

		else
		dp[i] = false;
	}

// if dp[n] is true beerus wins otherwisw whis wins
	return dp[n] ? "Beerus" : "Whis";
}
