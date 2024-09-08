/*
Problem statement
Implement a Queue Data Structure specifically to store integer data using a Singly Linked List.

The data members should be private.

You need to implement the following public functions :

1. Constructor:
It initialises the data members as required.

2. enqueue(data) :
This function should take one argument of type integer. It enqueues the element into the queue and returns nothing.

3. dequeue() :
It dequeues/removes the element from the front of the queue and in turn, returns the element being dequeued or removed. In case the queue is empty, it returns -1.

4. front() :
It returns the element being kept at the front of the queue. In case the queue is empty, it returns -1.

5. getSize() :
It returns the size of the queue at any given instance of time.

6. isEmpty() :
It returns a boolean value indicating whether the queue is empty or not.

Operations Performed on the Stack:
Query-1(Denoted by an integer 1): Enqueues an integer data to the queue.

Query-2(Denoted by an integer 2): Dequeues the data kept at the front of the queue and returns it to the caller.

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the front of the queue but doesn't remove it, unlike the dequeue function.

Query-4(Denoted by an integer 4): Returns the current size of the queue.

Query-5(Denoted by an integer 5): Returns a boolean value denoting whether the queue is empty or not.
  */


/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

**************************************************************/

class Queue {
	// Define the data members
	Node* head;
	Node* tail;
	int size;
   public:
    Queue() {
		head=NULL;
		tail=NULL;
		size=0;
		// Implement the Constructor
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		// Implement the getSize() function
		return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
	return size==0;
	}

    void enqueue(int data) {
		// Implement the enqueue() function
		Node* newNode= new Node(data);

		if(head==NULL){
			head=newNode;  
			tail=newNode;
		}
		else{
			tail->next=newNode;  //add element at last i.e at tail->next
			
			tail=newNode;  //tail will be updated to newNode
		}
		size++;
	}

    int dequeue() {
        // Implement the dequeue() function
		if(isEmpty())
		return -1;

		int ans=head->data;  //store head's data in ans variable
		
		Node* temp=head;  //temp is pointing to head
		
		head=head->next;  
		delete temp;  //delete the previous element
		size--;
		
		return ans;
    }

    int front() {
        // Implement the front() function
		if(isEmpty())
		return -1;

		return head->data;
    }
};
