/*
Problem statement
You are given an array/list ‘ARR’ of ‘N’ integers. You have to generate an array/list containing squares of each number in ‘ARR’, sorted in increasing order.

For example :

Input:
‘ARR’ = [-6,-3, 2, 1, 5] 

If we take a square of each element then the array/list will become [36, 9, 4, 1, 25].
Then the sorted array/list will be [1, 4, 9, 25, 36].

Output :
[1, 4, 9, 25, 36].
*/

#include <bits/stdc++.h> 
vector < int > sqsorted(vector < int > & arr) {
    int n=arr.size();
    vector<int> sq(n);
    for(int i=0;i<n;i++){
        sq[i]=arr[i]*arr[i];
    }
    sort(sq.begin(),sq.end());
    return sq;
}
