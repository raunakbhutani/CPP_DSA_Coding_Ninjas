/*
Problem statement
You are given an array 'ARR' of 'N' distinct positive integers. You are also given a non-negative integer 'B'.

Your task is to return all unique combinations in the array whose sum equals 'B'. A number can be chosen any number of times from the array 'ARR'.

Elements in each combination must be in non-decreasing order.
  */

#include <vector>

void comb(vector<int>& ARR, int B, vector<vector<int>>& res, vector<int>& current,int index){

    if(B == 0){  // base case: when rem sum = 0 add comb to result

        res.push_back(current);
        return;
    }

    // recursive case: iter8 through curr idx
    for(int i = index; i < ARR.size(); i++){

        if(ARR[i] > B)  // if the curr elem is greater than sum
        break;

        current.push_back(ARR[i]);

        comb(ARR, B - ARR[i], res, current, i);  // call rec with the upd8ed rem sum

        current.pop_back();  // backtrack to explore other options by removing the last elem
    }
}
vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    // Write your code here.

    sort(ARR.begin(), ARR.end());  // comb are in ascending order(non dec order)

    vector<vector<int>> result;  // vector to store all the comb

    vector<int> current;  // temp vector to store the curr elem

    comb(ARR, B, result, current, 0);

    return result;
}
