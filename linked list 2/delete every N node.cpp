/*
Problem statement
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.'
Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list. Indexing starts from 1.

To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
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

Node *skipMdeleteN(Node *head, int M, int N){
	// Write your code here
	if(head==NULL || M<=0 || N<0)
	return 0;

	Node* curr=head;

	while(curr!=NULL){
		// SKIP M nodes till curr becomes NULL i.e end of LL
		for(int count=1;count<M && curr!=NULL;count++){
			curr=curr->next;
		}
		if(curr==nullptr)
		break;

		Node* temp=curr->next;  // start from the next node of curr

		// start from next node of curr & DELETE N nodes
		for(int count=1;count<=N && temp!=NULL;count++){
			Node* NodetoDelete=temp;
			temp=temp->next;
			delete NodetoDelete;
		}
		
		curr->next=temp;  // link previous node with remaining node
		
		curr=temp;  // set pointer for next iteration
	}
	return head;
}
