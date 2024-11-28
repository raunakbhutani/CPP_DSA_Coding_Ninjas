/*
Problem statement
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.

Note: The input data will be such that there will always be a solution
*/

#include<string>
#include<vector>
#include<climits>

int helper(char* s1, char* s2, int len1, int len2, int** dp){
// base cases:
    if(len1 <= 0)  // if string1 is empty
    return 1001;

    if(len2 <= 0)   // if string2 is empty
    return 1;

    if(dp[len1][len2] > -1)   // if alr visited
    return dp[len1][len2];

    int ans = 0;  // min no of steps

    int option1 = helper(s1 + 1, s2, len1 - 1, len2, dp);  // we are not considering first char of s1
   
    int i = 0;
    
    for(; i < len2; i++){

        if(s1[0] == s2[i])  // first occurence of s1[0] in s2
        break;
    }

    if(i == len2)  // if s1[0] is not found in s2
    return 1;

    int option2 = helper(s1 + 1, s2 + i + 1, len1 - 1, len2 - 1 - i, dp) + 1;

    ans = min(option1, option2);
    
    dp[len1][len2] = ans;  // store that ans in dp array

    return ans;
}

int solve(string s, string v) {
    // Write your code here

    char* s1 = new char[s.length()];

    char* s2 = new char[v.length()];

    for(int i = 0; i < s.length(); i++){  // copy char

    s1[i] = s[i];
    }

     for(int i = 0; i < v.length(); i++){   // copy char

    s2[i] = v[i];
    }

    int** dp = new int*[s.length() + 1];

    for(int i = 0; i <= s.length(); i++){
        
        dp[i] = new int[v.length() + 1];

        for(int j = 0; j <= v.length(); j++){

            dp[i][j] = -1;  // not visited val
        }
    }

    int result = helper(s1, s2, s.length(), v.length(), dp);

    return result;
}
