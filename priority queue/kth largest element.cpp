/*
Problem statement
Given an array 'arr' of random integers and an integer 'k', return the kth largest element in the array.
*/

#include<queue>
#include <algorithm>
int kthLargest(vector<int>&arr, int k) {
    // Write your code here

    priority_queue<int> maxHeap(arr.begin(), arr.end());

    for(int i=0; i<k-1; i++){  // extract the kth largest element k-1 times
        maxHeap.pop();  // & pop it
    }

    return maxHeap.top();  // now the kth largest element is present at top of queue

}
