/*
Problem statement
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
  */

/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/
#include <vector>
#include <algorithm>
#include <queue>

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here

	vector<Node<int>*> result;  // store the head of each linked list corresponding to each level of the binary tree
	
	if(root == NULL)
	return result;

	queue<BinaryTreeNode<int>*> q;
	q.push(root);

	while(!q.empty()){

		int size = q.size(); // no of nodes at that particular level

		Node<int>* levelHead = NULL;
		Node<int>* levelTail = NULL;

		for(int i=0; i<size; i++){
			
			BinaryTreeNode<int>* currentNode = q.front();  // node being removed from front of queue
			q.pop();

			Node <int>* newNode = new Node<int>(currentNode->data);

			if(levelHead == NULL){
				levelHead = newNode;
				levelTail = newNode;
			}
			
			else{ // new node is added to the end of the linked list, and levelTail is updated.
				
				levelTail->next = newNode;
				levelTail = newNode;
			}
			
			if(currentNode->left!=NULL)
			q.push(currentNode->left);

			if(currentNode->right!=NULL)
			q.push(currentNode->right);
		}
		result.push_back(levelHead);
	}

	return result;

}
