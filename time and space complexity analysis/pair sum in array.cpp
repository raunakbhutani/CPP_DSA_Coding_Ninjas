/*
  Problem statement
You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.

Note:
Given array/list can contain duplicate elements. 
*/

#include<algorithm>

int pairSum(int *arr, int n, int num){

int pair=0;
     int j;

for(int i=0;i<n;i++){
     for(j=i+1;j<n;j++){
          if(arr[i]+arr[j]==num){
               pair++;
          }
     }
}
return pair;
}
