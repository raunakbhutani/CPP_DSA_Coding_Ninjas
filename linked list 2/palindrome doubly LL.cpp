/*
Problem statement
You have been given a head to a doubly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
  */

/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
			Node *prev;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
				this->prev = NULL;
	        }
        };

*****************************************************************/
bool palindromeDLL(Node* head){
    
	if(head==NULL || head->next==NULL)
		return true;

  // we are making 2 ptrs start(head) & tail (end) to keep track of the palindrome in LL

	Node* tail=head;

	while(tail->next!=NULL){   // find the tail of the LL
			tail=tail->next;       // it will move to the end of the LL
	}

	Node* start=head;

        while (start != tail && start->prev != tail) {
                        if (start->data != tail->data) // if corresponding
                                                       // elements do not match
                return false;

                        start = start->next; // move start ptr forward
                        tail = tail->prev;   // move tail ptr backward
        }

        return true;
        
		}
