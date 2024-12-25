/*
Problem statement
You are given two strings 'A' and 'B' of words. Your task is to find out the most frequent and lexicographically smallest word in string 'A', which is not present in string 'B'. If no such word is present in 'A', then return -1.

Note:

1. A word is a sequence of one or more lowercase characters.

2. Words are separated by a single whitespace character.
Example:
For the given string 'A' = “coding ninjas coding ninjas” and 'B' = “data structures and algorithms”, so both the word 'coding' and 'ninjas' are not present in string 'B' and occur two times each, but the word “coding” is lexicographically smaller than the word “ninjas”. So the answer is “coding”.
  */

#include <bits/stdc++.h> 
string mostFrequentWord(string &a, string &b) {
	// Write your code here.
	unordered_map<string, int> freqA;  // Frequency map for words in A
    unordered_set<string> wordsB;     // Set of words in B

    // Helper to split a string into words
    auto splitWords = [](const string &str) {
        vector<string> words;
        stringstream ss(str);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    };

    // Parse words in A
    for (const string &word : splitWords(a)) {
        freqA[word]++;
    }

    // Parse words in B
    for (const string &word : splitWords(b)) {
        wordsB.insert(word);
    }

    // Find the most frequent and lexicographically smallest word in A not in B
    string result = "-1";
    int maxFrequency = 0;

    for (const auto &[word, frequency] : freqA) {
        if (wordsB.find(word) == wordsB.end()) { // Word not in B
            if (frequency > maxFrequency || (frequency == maxFrequency && word < result)) {
                result = word;
                maxFrequency = frequency;
            }
        }
    }

    return result;
}
