/*
Problem statement
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).

From a cell (i, j), you can move in three directions:

1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
  */

int minCostPath(int **input, int m, int n) {
  
// using DP
  int **output = new int*[m];  

  for (int i = 0; i < m; i++){

	  output[i] = new int[n];
  }

// first fill the last cell
	output[m - 1][n - 1] = input[m - 1][n - 1];

// fill last row from right to left
	for(int j = n - 2; j >= 0; j--){

		output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
	}

// fill last col from bottom to up
	for(int i = m - 2; i >= 0; i--){

		output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
	}

// fill remaining cells
	for(int i = m - 2; i >= 0; i--){
		for(int j = n - 2; j >= 0; j--){

			output[i][j] = min(output[i][j + 1], min(output[i + 1][j + 1], output[i + 1][j])) + input[i][j];  // take min of right, diag, down + input
		}
	}

	int ans = output[0][0];

// dealloc8 memory
	for(int i =0; i < m; i++){
		delete[] output[i];
	}

	delete[] output;
	
	return ans;

}
