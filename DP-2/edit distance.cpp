/*
Problem statement
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.

Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note
Strings don't contain spaces
You need to find the edit distance from input string1 to input string2.
  */

int editDistance(string s1, string s2) {
	// Write your code here

	if(s1.length() == 0 || s2.length() == 0)  // if any of the strings is empty
	return max(s1.length(), s2.length());  // then we req 

	if(s1[0] == s2[0])  // if the 1st char of both strings is same
	return editDistance(s1.substr(1), s2.substr(1));  // then call rec from 2nd char of both the strings

	else{
		
		int x = editDistance(s1.substr(1), s2) + 1;   // insert
		
		int y = editDistance(s1, s2.substr(1)) + 1;   // delete

		int z= editDistance(s1.substr(1), s2.substr(1)) + 1;   // upd8

		return min(x, min(y, z));  // return the min ops required

	}

}
