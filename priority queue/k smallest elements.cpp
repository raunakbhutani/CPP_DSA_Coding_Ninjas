/*
Problem statement
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.

Notes :
1. Time complexity should be O(n * logk) and space complexity should not be more than O(k).
2. Order of elements in the output is not important.
*/
#include <queue>
#include <vector>
vector<int> kSmallest(int arr[], int n, int k) {

// use max Heap to keep track of smallest k elements
    priority_queue <int> pq;  // it stores the smallest k elements from the array

    for(int i=0; i<n; i++){
        if(pq.size() < k)  // if size of array is less than no of smallest elements 
        pq.push(arr[i]);  // then add the elements in array

        else if (arr[i] < pq.top()){  // if the current element is less than greatest element of k elements 
            pq.pop();  // then delete that element 
            pq.push(arr[i]);  // & add current element in array
        }
    }

// extract elements from heap & add them in this array
    vector<int> result;
    while(!pq.empty()){
        result.push_back(pq.top());
        pq.pop();
    }

    return result;
}
