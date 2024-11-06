/*
Problem statement
Implement the class for Max Priority Queue which includes following functions -



1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.



2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.



3. insert -
Given an element, insert that element in the priority queue at the correct position.



4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.



5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.



Note : main function is given for your reference which we are using internally to test the class.
*/

#include <vector>

class PriorityQueue {

    vector<int> pq;

    

   public:
     PriorityQueue() {}

    /**************** Implement all the public functions here ***************/

    void insert(int element) {

     pq.push_back(element);

     int childIndex = pq.size() - 1;

     while (childIndex > 0) {
       int parentIndex = (childIndex - 1) / 2;

       if (pq[childIndex] > pq[parentIndex]) { // if node's data at childIndex is greater 
        // node's data at parentIndex
         // then swap both of them
         int temp = pq[childIndex];
         pq[childIndex] = pq[parentIndex];
         pq[parentIndex] = temp;
       }

       else // if swapping is req before root only
         break;

       childIndex = parentIndex; // now parentIndex becomes childIndex
     }
}

    int getMax() {
       
    if(isEmpty())
    return -1;

    return pq[0];    // the max element is at root bcos of max heap prop
    }

    int removeMax() {
       
       if(isEmpty())
       return -1;

       int ans = pq[0];  // store the val at 1st pos in ans 
       pq[0] = pq[pq.size() - 1];  // now first element contains the val at last index
       pq.pop_back();   // now remove that element which was to be removed

       int parentIndex = 0;

       int leftChildIndex = 2 * parentIndex + 1;
       int rightChildIndex = 2 * parentIndex + 2;

       while(leftChildIndex < pq.size()){  // cond that we do not go out of the size of array

           int maxIndex = parentIndex;

           // now comp minIndex & children indexes
            if(pq[maxIndex] < pq[leftChildIndex])
            maxIndex = leftChildIndex;

            if(rightChildIndex < pq.size() && pq[maxIndex] < pq[rightChildIndex])
            maxIndex = rightChildIndex;

// if parent is larger than both children, then heap order prop is satissfied
            if(parentIndex == maxIndex)
            break;

// swap the parent with largest of element
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

// upd8 the values to continue the process
            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
       }
       return ans;
    }

    int getSize() {   // no of elem present in the priority queue.

        return pq.size();
    }

    bool isEmpty() {
       
       return pq.size() == 0;
    }
};
