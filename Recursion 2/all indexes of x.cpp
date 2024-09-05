 /*
Problem statement
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in the output array (in increasing order).

Do this recursively. Indexing in the array starts from 0.
*/

#include<algorithm>
int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
   if(size<=0){
        return 0;
    }
  
    int ans;
  
    ans = allIndexes(input, size-1, x, output);
  
    if(input[size-1] == x){
        output[ans] = size-1;
        return ans+1;
    }
      
    else
        return ans;
  
}
