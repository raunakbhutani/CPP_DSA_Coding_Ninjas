/*
Problem statement
For a given singly linked list of integers, arrange the nodes such that all the even number nodes are placed after the all odd number nodes. 
The relative order of the odd and even terms should remain unchanged.
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

Node *evenAfterOdd(Node *head) {
  // write your code here
  if (head == NULL || head->next == NULL)
    return head;

  Node *oddHead = NULL;
  Node *oddTail = NULL;
  Node *evenHead = NULL;
  Node *evenTail = NULL;
  Node *curr = head;

  while (curr != NULL) {
    // odd node
    if (curr->data % 2 != 0) {
      if (oddHead == NULL)
        oddHead = oddTail = curr;

      else {
        oddTail->next = curr;
        oddTail = oddTail->next;
      }
    } else {
      // even node
      if (evenHead == NULL)
        evenHead = evenTail = curr;

      else {
        evenTail->next = curr;
        evenTail = evenTail->next;
      }
    }
    curr = curr->next;
  }

  // connect odd list to even list
  if (oddHead == NULL)
    return evenHead;

  oddTail->next = evenHead;

  if (evenTail != NULL)
    evenTail->next = NULL; // end of even list must point to NULL

  return oddHead;
}
  
