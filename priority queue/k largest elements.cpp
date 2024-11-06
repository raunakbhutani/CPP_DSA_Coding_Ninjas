/*
Problem statement
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.

Time complexity should be O(nlogk) and space complexity should be not more than O(k).

Order of elements in the output is not important.
  */

#include<queue>
vector<int> kLargest(int input[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0; i<n; i++){   // traverse the whole array

    if(pq.size() < k)
    pq.push(input[i]);

    else if(input[i] > pq.top()){  // if current element is greater than smallest element of k element
        pq.pop();  // then delete it
        pq.push(input[i]);   // & add current element to array
    }
    }

    vector<int> result;
    while(!pq.empty()){

        result.push_back(pq.top());
        pq.pop();
    }

    return result;
}

  
