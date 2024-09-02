/*
Problem statement
You are given an array ‘Arr’ consisting of ‘N’ distinct integers and a positive integer ‘K’. Find out Kth smallest and Kth largest element of the array. It is guaranteed that K is not greater than the size of the array.

Example:

Let ‘N’ = 4,  ‘Arr’ be [1, 2, 5, 4] and ‘K’ = 3.  
then the elements of this array in ascending order is [1, 2, 4, 5].  Clearly, the 3rd smallest and largest element of this array is 4 and 2 respectively.
  */
#include<algorithm>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k){
	
sort(arr.begin(),arr.end());
int ksmall=arr[k-1];
int klarge=arr[n-k];

return {ksmall, klarge};
}
