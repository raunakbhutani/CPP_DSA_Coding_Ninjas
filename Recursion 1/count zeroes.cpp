/*
Problem statement
Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
  */
int helper(int n){
    if(n==0)
    return 0;
   int lastdig=n%10;
    if(lastdig==0)
    return 1+helper(n/10);
    else
    return 0+helper(n/10);
}
int countZeros(int n) {
    if(n==0)
    return 1;
    return helper(n);

}


