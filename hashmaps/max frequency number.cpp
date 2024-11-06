/*
Problem statement
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.

If two or more elements are having the maximum frequency, return the element which occurs in the array first.
  */

#include <unordered_map>
int highestFrequency(int arr[], int n) {
    unordered_map<int, int> freq;
    int maxFreq = 0;

    for(int i = 0; i < n; i++) {
        int num = arr[i];  // store the ith elem in num
        freq[num]++;  // inc the freq of num
        maxFreq = max(maxFreq, freq[num]);  // store the max of maxfreq &  freq[num]
    }
    
    for(int i = 0; i < n; i++) {
        if(freq[arr[i]] == maxFreq) {  // if that elem matches the max freq
            return arr[i]; // return that elem
        }
    }

    return -1; 
}
