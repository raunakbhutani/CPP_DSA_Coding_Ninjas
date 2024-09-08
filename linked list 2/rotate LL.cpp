/*
Problem statement
You are given a linked list having ‘n’ nodes and an integer ‘k’.

You have to rotate the linked list to the right by ‘k’ positions .
  */

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 **/

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head==nullptr || k==0)
          return head;

     Node* temp=head;

     int length=1;

     //find the length of LL
     while(temp->next!=NULL){
          
          temp=temp->next;

          length++;
     }

     // connect the last node to head to form a circular list
     temp->next=head;

     // calculate the effective rotations needed
     // ex 2%5=2
     k=k%length;

     int stepsToNewHead = length-k;

 // Find the new tail (which will be the old (stepsToNewHead-1)-th node)
     Node* newTail=head;

     for(int i=1;i<stepsToNewHead;i++){
          newTail=newTail->next;
     }

// The new head is the next node of the new tail
     Node* newHead=newTail->next;

// Break the circular list
     newTail->next=NULL;

     return newHead;
     
}
