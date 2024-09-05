/*
Problem statement
You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.

Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.
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

Node *deleteNode(Node *head, int pos){
    Node* temp=head;
	
	int idx=0;

	if(head==NULL)
	return NULL;

	if(pos==0){
		head=temp->next;    //update head
		delete temp;			
		return head;
	}
  
	while(temp!=NULL && idx<pos-1){
		temp=temp->next;
		idx++;
	}
  
	if (temp == nullptr || temp->next == nullptr) 
	return head;
	

	Node* a=temp->next;
	
  Node* b=a->next;
	
  temp->next=b;
	
	delete a;
	
return head;

}
