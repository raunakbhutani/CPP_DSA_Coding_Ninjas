/*
Problem statement
Ninja is playing with numbers but hates when he gets duplicate numbers.
Ninja is provided an array, and he wants to remove all duplicate elements and return the array, but he has to maintain the order in which the elements were supplied to him.
  */

#include <bits/stdc++.h> 
vector<int> removeDuplicates(vector<int> arr) {

  // Write your code here
  vector<int> output;  // vector to store unique elements
  unordered_map<int, bool> seen;  // map to store elemenets which occur once

  for(int i=0; i<arr.size(); i++){

    if(seen.count(arr[i]) > 0)  // if there are duplic8 elements 
    continue;  // then continue

    seen[arr[i]] = true;  // if element is unique return true
    output.push_back(arr[i]);  // add unique element in vector
  }

  return output;

}
