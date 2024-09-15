/*
Problem statement
Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.

LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 
  */

/**********************************************************

	Following is the Binary Tree Node class structure

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

***********************************************************/

int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    while (root != NULL) {

// if both values are less than root's data then move to LST
       if (val1 < root->data && val2 < root->data)
        root = root->left;

// if both values are greater than root's data move to RST
      else if (val1 > root->data && val2 > root->data)
        root = root->right;

// if val1 & val2 are on opposite sides or one of them is equal to root
	else
      return root->data;
    }	
	
	return -1;   // if the nodes are not found
}
