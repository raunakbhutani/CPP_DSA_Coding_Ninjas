/*
Problem statement
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.

Note: Space complexity should be O(1).
*/

void heapSort(int arr[], int n) {
    
    // build the heap in arr
    for(int i=0; i<n; i++){  // assume the 0th elem to be sorted

        // we will now up-heapify
        int childIndex = i;  // childIndex is 1st elem bcos new elem is entered at this position

        while(childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;

            if(arr[childIndex] < arr[parentIndex]){  // swap the elements if val at parentIndex > val at childindex
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else 
            break;

            childIndex = parentIndex;
        }
    }

    // now we wil sort the array by removing elements i.e down-heapify
    int size = n;
    while(size > 1){   // traverse just before the last elem as that would automatically be sorted
        
        // swap the first & last element
        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        
        size--;  // size of array is dec as the elem get sorted (i.e get enetered in heap)

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while(leftChildIndex < size){  // traverse till the whole array
       
        int minIndex = parentIndex;

        // now compare minIndex & children Indexes
        if(arr[minIndex] > arr[leftChildIndex])
        minIndex = leftChildIndex;

        if(rightChildIndex < size && arr[minIndex] > arr[rightChildIndex]) // stay within size of array
        minIndex = rightChildIndex;

        if(parentIndex == minIndex)
        break;

// swapping elements if val of node at parentIndex > val of node at any children index
        int temp = arr[parentIndex];
        arr[parentIndex] = arr[minIndex];
        arr[minIndex] = temp;

        // upd8 the values after performing 1 correct swap of element
        parentIndex = minIndex;
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = 2 * parentIndex + 2;


        }
       
    }
}
