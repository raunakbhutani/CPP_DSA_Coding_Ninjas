/*
Problem statement
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
  */

#include <unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int, int> subarray_sum;  // map to store the elem & its idx 

    int maxLength = 0;  // max length of subarray with sum = 0
    
    int sum = 0;  // sum of subarray

    for(int i=0; i < n; i++){
        sum += arr[i];  // keep on adding the sum 

        if(sum == 0)  
        maxLength = i + 1;  // max length will be 1 + the index at which sum = 0

        else{
            if(subarray_sum.find(sum) != subarray_sum.end())  // if we have encountered that sum 
            maxLength = max(maxLength, i - subarray_sum[sum]);  // we subtract rhat from current idx & check the max from maxLength & return the max of both bu upd8ing the maxLength

            else
            subarray_sum[sum] = i;  // if prefix sum  does not exist simply add that to the map
        }
    }
    return maxLength;
}
