/*
Problem statement
You are given a matrix ‘MAT’. Print and return the transpose of the matrix. The transpose of a matrix is obtained by changing rows to columns and columns to rows. In other words, transpose of a matrix A[][] is obtained by changing A[i][j] to A[j][i].

For example:
Let matrix be : 
1 2
3 4

Then transpose of the matrix will be: 
1 3
2 4
  */
#include <bits/stdc++.h> 
vector<vector<int>> transpose(int m, int n, vector<vector<int>> &mat){
    vector<vector<int>>transpose(n,vector<int>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            transpose[j][i]=mat[i][j];
        }
        cout<<endl;
    }
    return transpose;
}
