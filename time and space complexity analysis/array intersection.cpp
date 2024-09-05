/*
Problem statement
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; 
An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.

Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in ascending order.
  */

#include<algorithm>
void intersection(int *arr1, int *arr2, int n, int m) {
   
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    
    int i=0; 
    int j=0;
    
  while(i<n && j<m){
        if (arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            i++;
            j++;
        } 
          
        else if (arr1[i] > arr2[j])
            j++;
        else
        i++;
    }
}
