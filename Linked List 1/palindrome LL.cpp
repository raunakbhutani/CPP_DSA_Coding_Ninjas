/*
Problem statement
You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
  */
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
#include <algorithm>
#include <vector>
bool isPalindrome(Node *head)
{
    //Write your code here
	vector<int> ans;
	
	Node* temp=head;

	while(temp!=NULL){
		ans.push_back(temp->data); //store the elements(data) entered in the ans vector
		temp=temp->next;
	}

	int i=0, j=ans.size()-1;

	while(i<j){
		if(ans[i]!=ans[j])  // check whether the corresponding elements are equal or not
			return false;
			i++;
			j--;
	}
	return true;
}
