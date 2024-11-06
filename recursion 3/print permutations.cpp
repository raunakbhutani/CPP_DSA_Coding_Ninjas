/*
Problem statement
Given an input string (STR), print all possible permutations of the input string.

Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void helper(string input, string output){
	
	if(input.length() == 0){  // base case: if string is empty
		
		cout<<output<<endl;  // simply print O/P string
		return;
	}

	for(int i = 0; i <= output.length(); i++){  // traverse the output string for all poss positions

// we are placing the firstChar at diff pos in O/P
	string newOutput = output.substr(0, i) + input[0] + output.substr(i);
	
	helper(input.substr(1), newOutput);  // call recursion with rest starting from 1st idx of the 
	}
}
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	helper(input, "");
}
