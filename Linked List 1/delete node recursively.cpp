/*
Problem statement
Given a singly linked list of integers and position 'i', delete the node present at the 'i-th' position in the linked list recursively.

 Note :
Assume that the Indexing for the linked list always starts from 0.

No need to print the list, it has already been taken care. Only return the new head to the list.
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

Node *deleteNodeRec(Node *head, int pos) {
	
	if(head==NULL)   //base case i.e list is empty or is out of bounds
	return head;

	if(pos==0){
		Node* temp=head;
		head=head->next;
    
		delete temp;
    
		return head;
	}

	head->next = deleteNodeRec(head->next,pos-1);
	
	return head;
}
