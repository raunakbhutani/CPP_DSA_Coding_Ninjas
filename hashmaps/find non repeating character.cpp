/*
Problem statement
Ninja is now bored with numbers and is now playing with characters but hates when he gets repeated characters. Ninja is provided a string, and he wants to return the first unique character in the string.The string will contain characters only from the English alphabet set, i.e., ('A' - 'Z') and ('a' - 'z'). If there is no non-repeating character, print the first character of the string.
  If there is no non-repeating character, return the first character of the string.
  */

#include <bits/stdc++.h> 
char firstNonRepeatingCharacter(string str) {


  unordered_map<char, int> charCount;  // map to store the freq of each char in string

  // count he freq of each char in the string
  for(int i=0; i<str.length(); i++){
    
    charCount[str[i]]++;
  }

// find the char with freq = 1
  for (int i = 0; i < str.length(); i++) {  // traverse the whole string

      if(charCount[str[i]] == 1)  // if freq of elem is 1
      return str[i];  // return that unique char

    }

    return str[0];  // if no unique elem found, then return the first char of string
}
