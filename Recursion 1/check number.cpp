/*
Problem statement
Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.

Do this recursively.
  */

bool checkNumber(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if(size==0)
    return false;
    if(input[0]==x)
    return true;
    
    return checkNumber(input+1,size-1,x);

}
