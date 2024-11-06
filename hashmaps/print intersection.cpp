/*
Problem statement
You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.

Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the second array/list (ARR2).
*/

#include <unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {

    if(n == 0 || m == 0)  // if any of the arrays are empty
    return;
    
    unordered_map<int, int> freqMap;

    for(int i=0; i<n; i++){   // store the freq of each elem of arr1 in map
       freqMap[arr1[i]]++;  
    }

    for(int i=0; i<m; i++){  // iter8 through arr2 & print all common elem

        if(freqMap[arr2[i]] > 0){  // if freq of elem is more than 1
            cout<<arr2[i]<<endl;
            freqMap[arr2[i]]--;  // dec the freq from map to avoid duplicacy
        } 
    }
    cout<<endl;
}
