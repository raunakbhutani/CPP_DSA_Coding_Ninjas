/*
Problem statement
You have been given a singly linked list of integers. Write a function to print the list in a reverse order.

To explain it further, you need to start printing the data from the tail and move towards the head of the list, printing the head data at the end.

Note :
You can’t change any of the pointers in the linked list, just print the linked list in the reverse order.
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

void printReverse(Node *head){

    //Write your code here

	if(head==NULL)
	return;

	Node* curr=head;
	Node* prev=NULL;
	Node* next=curr->next;

	while(next!=NULL){
		curr->next=prev;
		prev=curr;
		curr=next;
		next=curr->next;
	}

	curr->next=prev;  //to upd8 last node

	while(curr!=NULL){
		cout<<curr->data<<" ";
		curr=curr->next;
	}

}
