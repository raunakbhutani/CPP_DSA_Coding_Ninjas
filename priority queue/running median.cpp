/*

Problem statement
You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.

Print only the integer part of the median.
  */

#include <queue>
void findMedian(int *arr, int n)
{
 
    priority_queue <int> leftHeap;  // max heap for left half of elements

    priority_queue <int, vector<int>, greater<int> > rightHeap;  // min heap for right half of elements
 
    for(int i=0; i<n; i++){
        if(leftHeap.empty() || arr[i] <= leftHeap.top())
        leftHeap.push(arr[i]);

        else
        rightHeap.push(arr[i]);

        // balance the heaps
    if(leftHeap.size() > rightHeap.size() + 1){
        rightHeap.push(leftHeap.top());
        leftHeap.pop();
    }

    else if (rightHeap.size() > leftHeap.size()){
        leftHeap.push(rightHeap.top());
        rightHeap.pop();
    }

   // print the median
    if(leftHeap.size() > rightHeap.size())
    cout<<leftHeap.top()<<" ";

    else
    cout<<(leftHeap.top() + rightHeap.top()) / 2<<" ";
    }


}
