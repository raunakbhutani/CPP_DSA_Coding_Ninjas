/*
Problem statement
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
  */

#include <iostream>
#include <string>
using namespace std;

string getChars(int d){  // func to map digits to corr char
    
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

    else
    return "";
}

void printKeypadHelper(int num, string output){

    if(num == 0){  // if num becomes 0 print O/P string

        cout<<output<<endl;
        return;
    }

    int lastDigit = num % 10;

    string CharToDigit = getChars(lastDigit);  // get corr char for the I/P digits

// Recur for each character that the current digit represents
    for(int i = 0; i < CharToDigit.length(); i++){

        printKeypadHelper(num / 10, CharToDigit[i] + output);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */

    if(num == 0)
    return;

    printKeypadHelper(num, "");

}

