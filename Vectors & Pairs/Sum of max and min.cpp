/*
Problem statement
You are given an array “ARR” of size N. Your task is to find out the sum of maximum and minimum elements in the array.

Follow Up:
Can you do the above task in a minimum number of comparisons?
  */
#include <utility>
#include <algorithm>
#include <climits>


int sumOfMaxMin(vector<int> arr, int n){
	int sum=0;
    
        auto it1=max_element(arr.begin(),arr.end());
        auto it2=min_element(arr.begin(),arr.end());
    sum=*it1+*it2;
    return sum;
}
