/*
Problem statement
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.

You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.

Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
  */

#include <unordered_map>
#include <vector>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here

    unordered_map<int, bool> numMap;  // map to store the elem with their val & each is marked true initially

    for(int i=0; i<n; i++){
        numMap[arr[i]] = true;  // mark all elem as true in map
    }

    int longestLength = 0;
    int start =0;
    int end = 0;

    for(int i=0; i < n; i++){  // iter8 through the array to find the seq 

        int num = arr[i];

        if(numMap.find(num - 1) == numMap.end()){  // if num - 1 is not present 
            int currentNum = num;  // then that is the start of the seq
            int currentLength = 1;  // now length becomes 1

        // extend the seq
        while(numMap.find(currentNum + 1) != numMap.end()){
            // inc their val
            currentNum++;  
            currentLength++;
        }
// upd8 the longest seq
        if(currentLength > longestLength){
            longestLength = currentLength;
            start = num;
            end = currentNum;
        }
        }
    }


    vector<int> result;  // vector to store the start & end values of longest length

    if(longestLength > 1){
// enter the starting & end values of longestLength        
        result.push_back(start);
        result.push_back(end);
    }

    else  // If the length of the longest possible seq is 1, then result must contain only single elem
    result.push_back(start);  

    return result;

}
