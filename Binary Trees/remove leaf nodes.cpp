/*
Problem statement
Given a binary tree, remove all leaf nodes from it. Leaf nodes are those nodes, which don't have any children.

Note:

1. Root will also be a leaf node if it doesn't have left and right child. 
2. You don't need to print the tree, just remove all leaf nodes and return the updated root.
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

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root == NULL)
	return NULL;  

    if (root->left == NULL && root->right == NULL) {  // if there is only root node present
        delete root;
        return NULL;
        }

	root->left = removeLeafNodes(root->left);
	
	root->right = removeLeafNodes(root->right);

	return root;
}
