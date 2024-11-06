/*
Problem statement
Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.
  */

bool isMaxHeap(int arr[], int n) {
    // Write your code here

    for(int i=0; i<=(n-2) / 2; i++){ 
// Internal Nodes: These are the nodes that have children and need to be checked.

     int leftChildIndex = 2 * i + 1;
     int rightChildIndex = 2 * i + 2;

    if(leftChildIndex < n && arr[i] < arr[leftChildIndex]) // if val of parent is less than that of left child node
    return false;

    if(rightChildIndex < n && arr[i] < arr[rightChildIndex])  // if val of parent is less than that of right child node
    return false;
    
}

    return true;
}
