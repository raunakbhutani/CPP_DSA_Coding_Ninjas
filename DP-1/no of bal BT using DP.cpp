/*
Problem statement
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.

This number can be huge, so, return output modulus 10^9 + 7.

Time complexity should be O(h).
*/

#include<cmath>
int balancedBTs(int n) {

    int* arr = new int[n + 1];

// base case

    if(n == 0 || n == 1)  // if ht of tree is 0(root) or 1 
    return 1;

    arr[0] = 1;  
    arr[1] = 1;

    int mod = (int)(pow(10, 9)) + 7;   // to prevent ans from going out of bounds 

    for(int i = 2; i <= n; i++){

        int x = arr[i - 1];
        int y = arr[i - 2];

        int temp1 = (int)(((long long)(x) * x) % mod);
        int temp2 = (int)((2 * (long long) (x) * y) % mod);

        arr[i] = (temp1 + temp2) % mod;

    }
    
    int ans = arr[n];  
    
    delete[] arr;

    return ans;
}
