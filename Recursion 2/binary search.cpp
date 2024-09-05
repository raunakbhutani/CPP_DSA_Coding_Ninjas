/*
Problem statement
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.

Return -1 if x is not present in the given array. Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)
*/

// input - input array
// size - length of input array
// element - value to be searched

int helper(int a[],int si,int ei,int x){
    if(si>ei)
    return -1;
  
    int mid=(si+ei)/2;
  
    if(a[mid]==x)
    return mid;
    
    if(a[mid]>x)
    return helper(a,si,mid-1,x);
    
    else
    return helper(a,mid+1,ei,x);
}

int binarySearch(int input[], int size, int element) {
   int si=0;
   int ei=size-1;
   
  helper(input,si,ei,element);
}
