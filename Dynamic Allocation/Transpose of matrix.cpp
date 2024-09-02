/*
Problem statement
Write a program to take a matrix of size m*n as the input from the user and print the transpose of the matrix. The transpose of a matrix is obtained by changing rows to columns and columns to rows. In other words, transpose of a matrix A[][] is obtained by changing A[i][j] to A[j][i]. Use dynamic memory allocation to create the 2D arrays.

For example:
Let matrix be : 
1 2
3 4

Then transpose of the matrix will be: 
1 3
2 4
*/
#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
 int m,n;
 cin>>m>>n;
 int **p=new int*[m];
 for(int i=0;i<m;i++){
	 p[i]=new int[n];
	 for(int j=0;j<n;j++){
		 cin>>p[i][j];
	 }
 }
for(int i=0;i<n;i++){
	 for(int j=0;j<m;j++){
		 cout<<p[j][i]<<" ";
	 }
	 cout<<endl;
 }
 for(int i=0;i<m;i++){
	 delete[] p[i];
 }
 delete[] p;
        }
}
