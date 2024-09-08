/*
Problem statement
You have been given a queue that can store integers as the data.
You are required to write a function that reverses the populated queue itself without using any other data structures.
*/


#include<queue>
void reverseQueue(queue<int> &input) {
	// Write your code here
	if(input.empty())
	return;

	int frontElement=input.front();   // output the first element
	
	input.pop();   // delete the first element

	reverseQueue(input);  // recursive call

	input.push(frontElement);  // add the firstElement back to the last of queue
}
