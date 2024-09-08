/*
Problem statement
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not.
Brackets are said to be balanced if the bracket which opens last, closes first.
  */

#include <algorithm>
#include<stack>
bool isBalanced(string expression) {

    // Write your code here
    stack <char> s;
    
    bool ans=true;

    for(int i=0;i<expression.size();i++){   //traverse the whole stack
        if(expression[i]=='(')
        s.push(expression[i]);  // push '(' i.e opening bracket in the stack 
    
        else if(expression[i]==')'){  // if element '(' is a closing bracket
        if (s.empty()) {              // then check whether the stack is empty
          return false; // If it is empty, it means there's no matching opening
                        // bracket, and the function returns false
        }

        s.pop(); // If the stack is not empty, pop the top element from the
                 // stack.
        }
    }

    return s.empty(); // function efficiently checks if all brackets in the  expression were matched correctly, ensuring the expression's balance.
}
