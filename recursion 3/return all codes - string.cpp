/*
Problem statement
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. And input string does not contain 0s.
*/

#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don?t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    
    if(input.empty()){
        output[0] = "";
        return 1;
    }

    int count = 0;  // to store the total no of codes
    
    // array to store the small O/P strings from recursive calls
    string smallOutput1[10000];
    string smallOutput2[10000];

// option 1: take the first dig & convert it into a char
    int firstdig = input[0] - '0'; 

    if(firstdig >= 1 && firstdig <= 9){

        char firstchar = 'a' + firstdig - 1;  // map 1->'a', 2->'b'....

// recursively find codes for the substring after first dig
        int smallOutputSize1 = getCodes(input.substr(1), smallOutput1);

        for(int i = 0; i < smallOutputSize1; i++){
            output[count++] = firstchar + smallOutput1[i]; // prepend the firstChar in each code in smallOutput & store it in O/P array
        }
    }

// option 2: take the first 2 dig & convert them into char if valid
    
    if(input.length() >= 2){

        int firstTwodig = (input[0] - '0') * 10 + (input[1] - '0');  // convert first 2 dig to number

        if(firstTwodig >= 10 && firstTwodig <= 26){

            char firstTwoChar = 'a' + firstTwodig - 1;  // map 10->'j' 11->'k'.....

            // recursively find codes for the substring after first 2 dig
        int smallOutputSize2 = getCodes(input.substr(2), smallOutput2);

        for(int i = 0; i < smallOutputSize2; i++){

            output[count++] = firstTwoChar + smallOutput2[i]; // prepend the firstTwoChar in each code in smallOutput2 & store it in O/P array
        }
        }
    }

    return count;  
}

