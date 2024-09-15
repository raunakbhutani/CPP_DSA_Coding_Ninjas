/*
Problem statement
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.

Note:
Assume that the Binary Tree contains only unique elements. 
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

BinaryTreeNode<int>* buildTreeHelper(int* inorder, int* preorder, int inS, int inE, int preS, int preE){

	// preOrder ---->  ----root---- -----left-----  ----right-----
	// inOrder ---->   ----left---- -----root-----  ----right----- 

	if(inS > inE)  	// if array is empty
	return NULL;

	int rootData = preorder[preS];  // get the root value from preorder array

	int rootIndex = -1; 

	for(int i=inS; i<=inE; i++){  // find the rootIndex in inorder array
        if (inorder[i] == rootData) {
          rootIndex = i;
		  break;
        }
        }

	int lPreS = preS +1;
	
	int lInS = inS;
	
	int lInE = rootIndex - 1;
	
	int lPreE = lInE - lInS + lPreS;
	
	int rPreS = lPreE + 1;
	
	int rPreE = preE;
	
	int rInS = rootIndex + 1;
	
	int rInE = inE;


	BinaryTreeNode<int>* root = new BinaryTreeNode<int> (rootData);

	root->left = buildTreeHelper(inorder, preorder, lInS, lInE, lPreS, lPreE);

	root->right = buildTreeHelper(inorder, preorder, rInS, rInE, rPreS, rPreE);

	return root;
}



BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {

	return buildTreeHelper(inorder, preorder, 0, inLength-1, 0, preLength-1);

}
