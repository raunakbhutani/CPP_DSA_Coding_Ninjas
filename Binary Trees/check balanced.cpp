/*
Problem statement
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.

Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    
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

int checkHeight(BinaryTreeNode<int> *root, bool &isBalanced){
	
	if(root == NULL)
	return 0;
  
  // recursively calls the left & right height
	int leftHeight = checkHeight(root->left, isBalanced);
	
	int rightHeight = checkHeight(root->right, isBalanced);
	
	if(abs(leftHeight - rightHeight) > 1)
	isBalanced = false;

	return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
	
 	bool isBalancedTree = true;
	
	checkHeight(root, isBalancedTree);

	return isBalancedTree;
}
