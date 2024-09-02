/*
Given an array of length N, you need to find and return the sum of all elements of the array using the concept of pointer arithmetic and pointers.
*/
int sum(int *ar , int n)
{
    int s=0;
    for(int i=0;i<n;i++){
        s+=*(ar+i);
    }
    return s;
}
