/*
Problem statement
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.

Return empty string for numbers 0 and 1.

Note :
1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
  */

#include <string>
using namespace std;

string getString(int d){

    if(d == 2)
    return "abc";

    if(d == 3)
    return "def";

    if(d == 4)
    return "ghi";

    if(d == 5)
    return "jkl";

    if(d == 6)
    return "mno";

    if(d == 7)
    return "pqrs";

    if(d == 8)
    return "tuv";

    if(d == 9)
    return "wxyz";

    return " ";
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */

    if(num == 0){       // base case
        output[0] = "";  
        return 1;
    }

    int lastDigit = num % 10;  // ex 234 % 10 = 4
    int smallNumber = num / 10;  // ex 234 / 10 = 23

    int smallOutputSize = keypad(smallNumber, output);  // call recursion on smallNumber

    string options = getString(lastDigit);  // options of strings to be append at end of the string

    for(int i=0; i < options.length() - 1; i++){  // loop to make copies of strings
    // we will make copies 1 less than total as 1 we have already made above
        
        for(int j=0; j < smallOutputSize; j++){  // copy all the strings

            output[j + (i + 1) * smallOutputSize] = output[j];  // output[j] gives the loc of copied strings 
        }
    }

    int k = 0;
    for(int i=0; i < options.length(); i++){  // ex: "abc" then first we will append ''a'' after every input then ''b'' & then ''c''
        for(int j=0; j < smallOutputSize; j++){  // we have to work upon rows = smallOutputSize
            output[k] = output[k] + options[i];
            k++;
        }
    }

    return smallOutputSize * options.length();
}
