/*
Problem statement
For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position.

 Note :
Assume that the Indexing for the singly linked list always starts from 0.

If the given position 'i',  is greater than the length of the given singly linked list, then don't print anything.
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

void printIthNode(Node *head, int i) {
  
  Node *temp = head; // store add of head
  int idx = 0;

  while (temp != NULL) {
    if (idx == i) {
      cout << temp->data;
      return;
    } 
      
    else {
      temp = temp->next;
      idx++;
    }
  }
 
}
