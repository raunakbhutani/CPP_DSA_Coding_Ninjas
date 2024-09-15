/*
Problem statement
For a given Binary Tree of type integer, update it with its corresponding mirror image.
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

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
   
	if(root == NULL)
	return;

// recursively mirror the left & right trees
	mirrorBinaryTree(root->left);
	mirrorBinaryTree(root->right);

// swapping the left & right children

	BinaryTreeNode<int>* temp = root->left;
	root->left = root->right;
	root->right = temp;



}
