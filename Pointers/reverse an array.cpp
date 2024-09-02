/*
Problem statement
Given an array ar of n integers, reverse the elements of the array by using the concept of pointers.
*/
#include<cstring>
void reverse(int *ar,int n)
{
	int *start=ar;
	int *end=ar+n-1;
	while(start<end){
		int temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
}
