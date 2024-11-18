/*
Problem statement
You are given a string 'S'. Your task is to partition 'S' such that every substring of the partition is a palindrome. You need to return all possible palindrome partitioning of 'S'.

Note: A substring is a contiguous segment of a string.

For Example:
For a given string “BaaB”
3 possible palindrome partitioning of the given string are:
{“B”, “a”, “a”, “B”}
{“B”, “aa”, “B”}
{“BaaB”}
Every substring of all the above partitions of “BaaB” is a palindrome.
*/

#include <bits/stdc++.h> 
#include <vector>
bool ispal(const string &s, int start, int end) {

  while (start < end){

        if(s[start] != s[end])
        return false;

// 2 ptr approach
        start++;
        end--;
}
    return true;
}

void backtrack(const string &s, int start, vector<string>& path, vector<vector<string>>& result){

    if(start >= s.size()){   // base case: i.e we have traversed the whole vector 

        result.push_back(path);  // push the current path to the result
        return;
    }

    for(int end = start; end < s.size(); end++){  // end is the starting idx of current elem being processed
        
        if(ispal(s, start, end)){

            path.push_back(s.substr(start, end - start + 1));  // extract the substr from start to end & add that to the path

            backtrack(s, end + 1, path, result);   // backtrack func used with the next starting idx(end + 1)
            
            path.pop_back();  // last substr are removed to explore other outcomes
        }
    }

}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> result;
    
    vector<string> path;

    backtrack(s, 0, path, result);

    return result;
}
