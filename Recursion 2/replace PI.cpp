/*
Problem statement
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
  */

#include <cstring>
void replacePi(char input[]) {
    if (input[0] == '\0' || input[1] == '\0') {
        return;
    }

   if(input[0]=='p' && input[1]=='i'){  // if first index 
   
           int last_idx=strlen(input);
     
           for (int i = last_idx; i >= 2; i--) {
             input[i + 2] = input[i];
           }

           // replace pi with 3.14
           input[0] = '3';
           input[1] = '.';
           input[2] = '1';
           input[3] = '4';

           replacePi(input + 4);
   }
     
   else
   replacePi(input+1);
       }




