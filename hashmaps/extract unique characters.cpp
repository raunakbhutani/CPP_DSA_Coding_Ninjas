/*
Problem statement
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once.
  The respective order of characters should remain same, as in the input string.
  */

#include <unordered_map>
#include <string>

string uniqueChar(string str) {
	
	unordered_map<char, bool> seen;  // map to store the keys as char & bool to check whether that key is already seen or not
	string result;

	for(int i=0; i<str.length(); i++){
		char ch = str[i];
		
		if(seen.find(ch) == seen.end()){   // if the char has not been seen before
			seen[ch] = true;  // mark the char as seen
			result += ch;  // add that char to result string
		}
	}
	return result;
}
