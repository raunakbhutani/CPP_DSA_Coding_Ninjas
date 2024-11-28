/*
Problem statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.

Note
Space complexity should be O(W).
*/

#include<vector>
int knapsack(int* weight, int* value, int n, int maxWeight) {
	
// created a 1D array of size maxWeight + 1 & all elem are initialised to 0
	vector<int> dp(maxWeight + 1, 0);  

	for(int i = 0; i < n; i++){
		// traverse the dp array from right to left
		for(int j = maxWeight; j >= weight[i]; j--){
			
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}

	return dp[maxWeight];
}
