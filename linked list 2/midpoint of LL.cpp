/*
Problem statement
For a given singly linked list of integers, find and return the node present at the middle of the list.

Note :
If the length of the singly linked list is even, then return the first middle node.

Example: Consider, 10 -> 20 -> 30 -> 40 is the given list, then the nodes present at the middle with respective data values are, 20 and 30. We return the first node with data 20.
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

Node *midPoint(Node *head)
{
    // Write your code here
	if(head==NULL)
	return NULL;

	Node* slow=head;
	Node* fast=head->next;

	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;  //move fwd by 1
		fast=fast->next->next;  //move fwd by 2
	}
	//slow ptr will always pt to mid element
	return slow;
}
