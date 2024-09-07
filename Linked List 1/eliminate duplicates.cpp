/*
Problem statement
You have been given a singly linked list of integers where the elements are sorted in ascending order.
Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.
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

Node *removeDuplicates(Node *head){
    //Write your code here
	if(head==NULL)
	return head;

	Node* curr=head;

        while (curr->next != NULL) { 

        if (curr->data == curr->next->data)
          curr->next = curr->next->next; 	//point to next element of curr

        else
          curr = curr->next;  //connect to the unrepeated element
        
		}
		
		return head;
		
}
