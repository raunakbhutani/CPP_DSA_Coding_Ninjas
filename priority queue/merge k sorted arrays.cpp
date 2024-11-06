/*
Problem statement
Given k no. of different size arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).

Hint : Use Heaps.
*/

#include <queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here

    priority_queue<int, vector<int>, greater<int> > pq;  // min heap

    for(int i=0;i<input.size(); i++){
        vector<int>* current = input[i];
        for(int j=0; j<current->size(); j++){

            pq.push(current->at(j));
        }
    }
    
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
