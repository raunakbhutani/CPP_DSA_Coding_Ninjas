/*
Problem statement
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.
  */

bool helper(char input[], int index){

	if(input[index] == '\0')   // if we reach the end of string i.e base case
	return true;

	if(input[index] == 'a'){  // if curr char is 'a'

// if the next char is 'a' or '\0', 
		if(input[index + 1] == 'a' || input[index + 1] == '\0')
		return helper(input, index + 1); // continue after idx 1

// if the next char are "bb" 
		else if(input[index + 1] == 'b' && input[index + 2] == 'b' && input[index + 3] != 'b')
		return helper(input, index + 3);  // continue after idx 3

// if none of the condition is met
		else 
		return false;
	}

 // if curr char is "bb"
	if(input[index] == 'b' && input[index + 1] == 'b'){ 

// if the next char is 'a' or '\0' 
		if(input[index + 2] == 'a' || input[index + 2] == '\0')
		return helper(input, index + 2);  // continue with char after 2nd idx

		else  // if none of the condition is met
		return false;
	}

	return false;  // if curr char is neither 'a' nor "bb"
}



bool checkAB(char input[]) {
	// Write your code here

	if(input[0] != 'a')   // if the string starts with 'a'
	return false;

	return helper(input, 0);
}

