/*
Problem statement
Given a singly linked list of integers, sort it using 'Bubble Sort.'
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
#include <algorithm>

Node *bubbleSort(Node *head){
	
	if(head==NULL || head->next==NULL)
		return head;

		Node* current=head;
		
		Node* last=NULL;

		bool swapped;
	
	do{
		
		swapped=false;

		current=head;

		while(current->next!=last){
                  if (current->data > current->next->data) { 	 // Compare current node with next node 
                    swap(current->data, current->next->data);  // and swap if it is greater
						swapped=true;
                  }
				  current=current->next;  // move to the next node
                }

				last=current;  // update the last sorted list
				
	}while(swapped);

	return head;
}
