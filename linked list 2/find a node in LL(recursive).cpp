/*
Problem statement
Given a singly linked list of integers and an integer n, find and return the index for the first occurrence of 'n' in the linked list. -1 otherwise.

Follow a recursive approach to solve this.
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

int findNodeRec(Node *head, int n){

	if(head==NULL)
		return -1;

	// int index=0;
	
	if(head->data==n)  // element found at head only
		return 0;    

	int index=findNodeRec(head->next, n);

	if(index!=-1)
		return index+1;

	else
		return -1;
}
