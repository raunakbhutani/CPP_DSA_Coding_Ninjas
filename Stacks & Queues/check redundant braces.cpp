/*
Problem statement
For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.

A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.

Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.
Note:
You will not get a partial score for this problem. You will get marks only if all the test cases are passed.
Return "false" if no brackets are present in the input.
  */


#include <stack>
#include <string>
using namespace std;

bool checkRedundantBrackets(string expression) {
    stack<char> s;
    
    // inside the loop, expression[i] accesses the character at the current position i in the string.
    for (int i = 0; i < expression.size(); i++) {
        char ch = expression[i];
        
        
        if (ch == ')') {
            char top = s.top();
            s.pop();
            
            // Flag to check if there is any operator inside the brackets
            bool hasOperator = false;

        // Check characters inside the current pair of parentheses
            while (!s.empty() && top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    hasOperator = true;
                }
                top = s.top();
                s.pop();
            }
            
            // If no operator was found, it's a redundant bracket
            if (!hasOperator) 
                return true;
            
        } 
        else 
            s.push(ch);
        
    }
}
