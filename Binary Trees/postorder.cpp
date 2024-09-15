/*
Problem statement
For a given Binary Tree of integers, print the post-order traversal.
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

void postOrder(BinaryTreeNode<int> *root) {
	
// in post order first the data of children of root gets printed & at last root node gets printed

	if(root == NULL)
	return;


	postOrder(root->left);
	postOrder(root->right);

	cout<<root->data<<" ";
}
