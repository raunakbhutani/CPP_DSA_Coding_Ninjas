/*
Problem statement
You are given an unsorted array containing ‘N’ integers. You need to find ‘K’ largest elements from the given array and fill those K elements in the given output array.

Note:
We recommend you to use inbuilt function of cpp library.
You don't need to return or print anything it has already been taken care of. Just implement the given function and fill the output array as required.
*/

void Klargest(int arr[],int output[],int n,int k){
   
    sort(arr,arr+n); 
        int j=0;
        for (int i = n - k; i < n; i++) {
          output[j] = arr[i];
          j++;
        }
    }
    
