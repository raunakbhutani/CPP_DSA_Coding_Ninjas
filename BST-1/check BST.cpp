/*
Problem statement
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.

Note:
Duplicate elements should be kept in the right subtree.
*/

/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<climits>

bool isBSThelper(BinaryTreeNode<int> *root, int minVal, int maxVal){

	if(root == NULL)
	return true;

	if(root->data <= minVal || root->data >= maxVal)
	return false;

// Check the LST with an updated max value (root->data) 
// and the RST with an updated min value (root->data).

	return isBSThelper(root->left, minVal, root->data) && isBSThelper(root->right, root->data, maxVal);
}

bool isBST(BinaryTreeNode<int> *root) {
	
	// we are covering the full range here of integer values
	return isBSThelper(root, INT_MIN, INT_MAX);
	
}
