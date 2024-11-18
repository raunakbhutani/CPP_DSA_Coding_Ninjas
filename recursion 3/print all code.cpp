/*
Problem statement
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. Just print them in different lines.
  */

#include <string.h>
using namespace std;

void helper(string input, string output){

    if(input.empty()){  // base case: if I/P string is empty
        cout<<output<<endl;
        return;
    }

    int firstDig = input[0] - '0';  // convert first dig to int

    if(firstDig > 0){  // valid single digit

        char firstChar = 'a' + firstDig - 1;
        helper(input.substr(1), output + firstChar);
    }
 
    if(input.length() >= 2){  // consider the first 2 char as singl dig

        int firstTwoDigit = (input[0] - '0') * 10 + (input[1] - '0');  // convert them to int

        if(firstTwoDigit >= 10 && firstTwoDigit <= 26){

            char firstTwoChar = 'a' + firstTwoDigit - 1;  // convert to corr char
            helper(input.substr(2), output + firstTwoChar);  // call rec for next string
        }

    }

}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    helper(input, "");
}

