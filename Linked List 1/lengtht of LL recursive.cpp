/*
Problem statement
Given a linked list, find and return the length of the given linked list recursively.
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

int length(Node *head) {

	Node* temp=head;

	if(head==NULL)
	return 0;

	return 1 + length(head->next);

}
