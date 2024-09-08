/*
Problem statement
You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty.
You are required to write a function that reverses the populated stack using the one which is empty.
*/

#include <stack>
void reverseStack(stack<int> &input, stack<int> &extra) {
    
    // This step reverses the order of the elements because the last element of s1 becomes the first element of s2.
  
   //1
   //2
   //3
   //4

   // first method
    // while(!input.empty()){
    //     int temp=input.top();
    //     input.pop();
    //     extra.push(temp);
    // }
    // input=extra;
    
    // This step ensures that s1 now contains the elements in reversed order.
    //4
    //3
    //2
    //1

    // while(!extra.empty()){
    //     int temp=extra.top();
    //     extra.pop();
    //     input.push(temp);
    // }
    
    // second method using recursion
    if(input.empty())
    return;

    int temp=input.top();
    input.pop();

    reverseStack(input,extra);  
    
while(!input.empty()){
        int temp=input.top();
        input.pop();
        extra.push(temp);
    }
    
    input.push(temp);
    
 while(!extra.empty()){
        int temp=extra.top();
        extra.pop();
        input.push(temp);
    }
}
