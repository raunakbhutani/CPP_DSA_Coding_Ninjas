/*
Problem statement
Given a string S, find and return all the possible permutations of the input string.

Note 1 : The order of permutations is not important. Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
  */

#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/

	if(input.length() == 0 || input.length() == 1){  // if a string is empty or contains a single char
		
		output[0] = input;   // insert that at first idx
		return 1;  // O/P = 1
	}

	string smallOutput[1000];  // create a string array to store smallO/P on which we call recursion

	int smallOutputSize = returnPermutations(input.substr(1), smallOutput);  // size of that small string excluding the first char

	char firstChar = input[0];

	int k = 0;
	for(int i = 0; i < smallOutputSize; i++){  // traverse entire smallOutput array & go till 
		
		for(int j = 0; j <= smallOutput[i].length(); j++){  // traverse each char of smallO/P array
		
			output[k] = smallOutput[i].substr(0, j) + firstChar + smallOutput[i].substr(j);  
			k++;
		}
	}
	return k;
}
