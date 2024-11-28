/*
Problem statement
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s.
  You need to return the size of the square matrix with all 0s.
  */

#include<climits>
int findMaxSquareWithAllZeros(int **arr, int n, int m){
// create a dp table to store the size of largest square sub matrix ending at each cell

	int** dp = new int*[n];  // DP table with n rows

	for(int i = 0; i < n; i++){

		dp[i] = new int[m];  // create m cols for each row
	}
	
	int maxSquareSize = 0;  // to check largest sqaure matrix found with all 0s

// initialise the DP array
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){

			if(i == 0 || j == 0)   // base case for 1st row / col 
			dp[i][j] = (arr[i][j] == 0) ? 1 : 0;

			else if(arr[i][j] == 0)   // if current cell is 0
// if we encountered a 0
// check for TOP i.e dp[i - 1][j], LEFT i.e dp[i][j - 1], & TOP LEFT DIAG i.e dp[i - 1][j - 1]
			dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;  

			else  // if current cell is 1
			dp[i][j] = 0;

// upd8 the maxSquareSize if it is
			maxSquareSize = max(maxSquareSize, dp[i][j]);
		}
	}

	for(int i = 0; i < n; i++){

		delete[] dp[i];
	}

	delete[] dp;

	return maxSquareSize;
}
