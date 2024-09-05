/*
Problem statement
Write a recursive function to convert a given string into the number it represents. 
That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
  */

#include<cmath>
int stringToNumber(char input[]) {
    int c=0;
  
    for(int i=0;input[i]!='\0';i++){  // len of input arr
        c++;
    }   
  
    if(c==0)
    return 0;   //base case
    
    int first_dig=input[0]-'0';    //converts first dig char to int by subt ASCII val of 0
    
    int remaining=stringToNumber(input+1); 
  
    int ans=first_dig*pow(10,c-1)+remaining;   //ex 1234 then 1 will be 1*10^(4-1)+234=1234
    
    return ans;
}

/*
// how it works -->
Fourth call returns: 4 * pow(10, 1-1) + 0 = 4
Third call returns: 3 * pow(10, 2-1) + 4 = 3 * 10 + 4 = 34
Second call returns: 2 * pow(10, 3-1) + 34 = 2 * 100 + 34 = 234
First call returns: 1 * pow(10, 4-1) + 234 = 1 * 1000 + 234 = 1234
  */
