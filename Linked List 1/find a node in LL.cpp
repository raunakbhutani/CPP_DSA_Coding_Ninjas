/*
Problem statement
You have been given a singly linked list of integers. Write a function that returns the index/position of integer data denoted by 'N' (if it exists). 
Return -1 otherwise.

Note :
Assume that the Indexing for the singly linked list always starts from 0.
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

int findNode(Node *head, int n){
    // n is no to be searched

    int index=0;  //keeps track of the index u are at
    Node* temp=head;   //store add of head

    while(temp!=NULL){  //keep traversing till end of list
      
      if (temp->data==n)  //if data of current node is equal to no to be found
        return index;
      
      temp=temp->next;
      index++;
      
    }
    return -1;
}
