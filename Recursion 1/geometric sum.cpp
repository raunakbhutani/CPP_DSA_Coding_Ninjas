/*
Problem statement
Given k, find the geometric sum i.e.

1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
Note :
using recursion.
  */
#include <cmath>
double geometricSum(int k) {
    // Write your code here
if(k==0)
return 1;
  
return geometricSum(k-1)+1/pow(2,k);
}


