/*
Problem statement
For a given Binary Tree of integers, find and return the height of the tree.
Height is defined as the total number of nodes along the longest path from the root to any of the leaf node.
  */

/***********************************************************
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

int height(BinaryTreeNode<int>* root) {
    
	if(root == NULL)  // empty tree has height = 0
	return 0;

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return 1 + max(leftHeight, rightHeight);  // return height(+1(for root)) from the side where it is max


}
