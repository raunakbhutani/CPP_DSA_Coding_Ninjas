/*
Problem statement
Given a singly linked list of integers and position 'i', insert the given node at the 'i-th' position in the linked list recursively.

 Note :
Assume that the Indexing for the linked list always starts from 0.

No need to print the list, it has already been taken care. Only return the new head to the list.
  */

Node* InsertNode(Node *head, int pos, Node* newNode){
    //base case
    if (pos == 0) { // position is at 0th idx

      newNode->next = head;
      return newNode;
    }

    if (head == NULL)
      return head;

    head->next = InsertNode(head->next, pos - 1, newNode);
    
    return head;
    
}
