/*
Problem statement
Given an array of n integers, find and return the pointer type reference to the highest element of the array. 
For example if the array is "1 2 3 4 5", you have to return the pointer type variable holding the address of "5".
  */
#include<bits/stdc++.h>
using namespace std;
int* findmax(int *ar,int n)
{
    int* highest=ar;  //highest ptr stores add of ar[0]
    for(int i=0;i<n;i++){
        if(ar[i]>*highest){
            highest=&ar[i];
        }
    }
return highest;
}
