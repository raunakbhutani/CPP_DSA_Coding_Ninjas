/*
Problem statement
Given an array ar of n integers, find the minimum and maximum value in the array and store their addresses in separate pointer variables. 
Then, modify the values at the addresses pointed by these pointers setting the minimum value to 0 and maximum value to 100.
*/
#include<climits>
void modify(int *ar,int n)
{
	int max=INT_MIN;
	int min=INT_MAX;
	int maxidx=-1;
	int minidx;
	for(int i=0;i<n;i++){
		if(ar[i]>max){
			max=ar[i];
			maxidx=i;
		}
		if(ar[i]<min){
			min=ar[i];
			minidx=i;
		}
	}
	ar[maxidx]=100;
	ar[minidx]=0;
}
