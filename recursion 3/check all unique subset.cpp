/*
Problem statement
You are given an sorted integer array of size 'n'.
Your task is to find and return all the unique subsets of the input array.
Subsets are arrays of length varying from 0 to 'n', that contain elements of the array. But the order of elements should remain the same as in the input array.
*/

#include <vector>
#include <algorithm>

void helper(int index, vector<int>& arr, vector<int>& current, vector<vector<int>>& result){

    result.push_back(current);  // base case: add the current subset to result

    for(int i = index; i < arr.size(); i++){

        if(i > index && arr[i] == arr[i -1])  // skip the duplic8es
        continue;

        current.push_back(arr[i]); // add the elem in array
        
        helper(i+1, arr, current, result);  // call recursion from the next idx

        current.pop_back();  // backtrack: remove the last elem to explore other subsets


    }
}

vector<vector<int>> getUniqueSubsets(vector<int>& arr) {
    // Write Your Code Here    

    vector<vector<int>> result;
    vector<int> current;

    sort(arr.begin(), arr.end());  // sort the array to gp together the duplic8es

    helper(0, arr, current, result);

    return result;  // return the vector holding all unique subsets of the input array.
}
