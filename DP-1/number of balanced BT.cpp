/*
Problem statement
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.

This number can be huge, so, return output modulus 10^9 + 7.

Write a simple recursive solution.
  */

#include<cmath>
int balancedBTs(int n) {
    // Write your code here
 
    if(n <= 1)  // base case: i.e when ht of bal BT = 0(root) or with 1 node only
    return 1;

    int mod = pow(10, 9) + 7;  // to prevent our ans from going out of bounds for large val of n
    
    int x = balancedBTs(n - 1);
    int y = balancedBTs(n - 2);

    int temp1 = (int)(((long long) (x) * x) % mod);
    
    int temp2 = (int)((2 * (long long)(x) * y) % mod);

    int ans = (temp1 + temp2) % mod;

    return ans;

}
