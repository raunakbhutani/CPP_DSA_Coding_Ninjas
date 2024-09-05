/*
Problem statement
You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.

Note :
Given array/list can contain duplicate elements.
  */

#include <algorithm>
int tripletSum(int *arr, int n, int num) {

  sort(arr,arr+n);
  
    int k=0;
  
   int count = 0;
  
    while(k<n)
    { 
    
        int i=k+1; 
        int j=n-1;
    
    
        int sum = num-arr[k];
        while(i<j){
        
            if (arr[i] + arr[j] == sum){  // if found triplet
            
                if(arr[i] == arr[j]) {  // case where all elements from i to j are equal as the array is sorted,, every element will make a triplet with each other thats why using sum formual to calculate them
                    int num = ((j - i)+1);
                    count += (num*(num-1))/2;
                    break;
                }

                int count1 = 1;
              
                while(arr[i] == arr[i + 1] && i < j) {  // this is the case where some elements from ith index are equal
                    count1++;
                    i++;
                }
              
                int count2 = 1;
                while(arr[j] == arr[j-1] && i < j) { // this is the case where some elements from jth index are equal
                    count2++;
                    j--;
                }
            
                count += (count1 * count2);  // adding their product as every ith element will make triplet with every jth element
                i++;
                j--;
            }
            else if(arr[i]+arr[j]>sum) // as the array is sorted if our sum is greater than required we will take lower element
                j--;
            
            else // if our sum is less then required sum
                i++;
          
        }
                k++;
    
        }
  
 return count;
}
