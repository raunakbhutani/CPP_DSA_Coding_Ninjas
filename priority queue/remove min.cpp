/*
Problem statement
Implement the function RemoveMin for the min priority queue class.

For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.

Note : main function is given for your reference which we are using internally to test the code.
*/

#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        if(isEmpty())
        return -1;

        int ans = pq[0];  // store the first node data in ans variable
        pq[0] = pq[pq.size() - 1];   // upd8 val of first element with last element

        pq.pop_back();  // remove the last element

        int parentIndex = 0;
        
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while(leftChildIndex < pq.size()){

            int minIndex = parentIndex;   // upd8 val of minIndex

            if(pq[minIndex] > pq[leftChildIndex])
            minIndex = leftChildIndex;

            if(rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex])
            minIndex = rightChildIndex;

            if(parentIndex == minIndex)  // we have placed all the elements at correct position
            break;

            // swapping elements if parentIndex(root) is greater than children's data

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            // upd8 the values after performing one correct swap of element
            parentIndex = minIndex;
            
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        
        return ans;
    }
};
