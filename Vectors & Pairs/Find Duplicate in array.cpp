/*
Problem statement
You are given an array of integers 'ARR' containing N elements. Each integer is in the range [1, N-1], with exactly one element repeated in the array.

Your task is to find the duplicate element. The duplicate element may be repeated more than twice in the error, but there will be exactly one element that is repeated in the array.

Note :

All the integers in the array appear only once except for precisely one integer which appears two or more times.
*/

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	
	vector<int> f(n,0);
	for(int i=0;i<n;i++){
		f[arr[i]]++;
	}
	for(int i=0;i<n;i++){
		if(f[i]>=2){
			return i;
		}
	}
}
