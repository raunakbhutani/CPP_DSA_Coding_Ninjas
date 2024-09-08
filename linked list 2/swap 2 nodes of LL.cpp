/*
Problem statement
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.'
Swap the nodes that are present at the 'i-th' and 'j-th' positions and return the new head to the list.
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

Node *swapNodes(Node *head, int i, int j){
	//Write your code here
	if(i==j)
	return head;

	Node* prev1=NULL;
	Node* curr1=head;

	while(i--){   
		prev1=curr1;  //prev1 is at loc just before i
		curr1=curr1->next;  // curr1 is at loc i
	}

	Node* prev2=NULL;
	Node* curr2=head;

	while(j--){
		prev2=curr2;
		curr2=curr2->next;
		
	}

	// swapping elements
	
	prev2->next=curr1;

	if(prev1!=NULL)
		prev1->next=curr2;
	
	else 
		head=curr2; // if its first node
	

	if(prev2!=NULL)
		prev2->next=curr1;
	
	else 
		head=curr1; // if its first node
	
	Node* temp=curr1->next;
	curr1->next=curr2->next;
	curr2->next=temp;
	
	return head;
	
}
