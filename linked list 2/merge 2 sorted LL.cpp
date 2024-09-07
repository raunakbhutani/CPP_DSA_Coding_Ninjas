/*
Problem statement
You have been given two sorted(in ascending order) singly linked lists of integers.

Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.

Note :
Try solving this in O(1) auxiliary space.

No need to print the list, it has already been taken care.
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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    //Write your code here
	if(head1==NULL)
	return head2;

	if(head2==NULL)
	return head1;

	// Initialize the Head and Tail of the Merged List
	Node* head=NULL; 
	Node* tail=NULL;

	// determine the first node of the merged list
	if(head1->data < head2->data){
		head=head1;
		head1=head1->next;
	}

	else{
		head=head2;
		head2=head2->next;
	}
	
	tail=head;

	// Merge Remaining Nodes
	while(head1!=NULL && head2!=NULL){
		
		if(head1->data < head2->data){
			tail->next=head1;   // Append the smaller node to the merged list by setting tail->next.
			head1=head1->next;
		}
		
		else{
			tail->next=head2;
			head2=head2->next;
		}
		
		tail=tail->next;

		// Append the remaining nodes to the end of the merged list by setting tail->next.
		if(head1!=NULL)
		tail->next=head1;

		else
		tail->next=head2;
	}
	
	return head;

}
