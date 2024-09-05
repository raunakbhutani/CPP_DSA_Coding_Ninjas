/*
Problem statement
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
  */

#include<cstring>
void pairStar(char input[]) {
    if(input[0]=='\0')
    return;
  
    pairStar(input + 1);
  
    if(input[0]==input[1]){ 
        int sz=strlen(input);
        for (int i = sz - 1; i > 0 ;i--) {
        input[i + 1] = input[i];
        }
      
        input[1] = '*';
    }
}
