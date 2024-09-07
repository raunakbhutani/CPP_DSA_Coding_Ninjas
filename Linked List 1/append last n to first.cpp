/*
Problem statement
You have been given a singly linked list of integers along with an integer 'N'. 
Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.

Hint:
Identify how many pointers you require and try traversing them to right places and connect nodes accordingly also don't forget to disconnect what's required else it could create cycles.
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

Node *appendLastNToFirst(Node *head, int n){
    //Write your code here
	if(n==0 || head==NULL)
	return head;

	Node* temp=head;

	int length=0;

	while(temp!=NULL){
		length++;
		temp=temp->next;
	}
	
	// If n is greater than or equal to the length, return the original head
	if(n>=length)
	return head;

	//find the (length-n) node
	Node* fast=head;
	Node* slow=head;

// Move the fast pointer n steps ahead in the list. 
// This helps create a gap of n nodes between the fast and slow pointers.

	for(int i=0;i<n;i++){
		fast=fast->next;    
	}
	
	// Move both fast and slow pointers until fast reaches the end
	while(fast->next!=NULL){
		slow=slow->next;
		fast=fast->next;
	}

	// 'slow' is now at the (length - n)th node
	Node* newHead=slow->next;
	slow->next=NULL;  //break the link

	// Find the end of the list to link to the original head
	fast->next=head;

	return newHead;
}
