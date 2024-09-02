/*
Problem statement
For a given two-dimensional square matrix of size (N x N). Find the total sum of elements on both the diagonals and at all the four boundaries.
  */

int totalSum(vector<vector<int>> input, int n)
{
    int sum=0;
    // row top bottom
    for(int i=0;i<n;i++){
        sum+=input[0][i];
        sum+=input[n-1][i];
    }
    // col top bot
    for(int i=1;i<n-1;i++){
        sum+=input[i][0];
        sum+=input[i][n-1];
    }
    // diag
    for(int i=1;i<n-1;i++){
        sum+=input[i][i];
        sum+=input[i][n-1-i];
    }
    if(n%2!=0){
        sum-=input[n/2][n/2];
    }
    return sum;
}
