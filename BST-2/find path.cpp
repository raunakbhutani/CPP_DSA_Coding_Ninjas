/*
Problem statement
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list.
Return empty list otherwise.

Note: Assume that BST contains all unique elements.
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
#include <algorithm>

bool findPath(BinaryTreeNode<int>* root, int key, vector<int>& path){

	if(root == NULL)
	return false;

    if (root->data == key) {
    
	path.push_back(root->data);	 // push this element in the vector
	return true;
    }

	if(root->data < key){  // if value of root is less than entered value

		bool temp = findPath(root->right, key, path);  // then search in RST
		
		if(temp == true)
		path.push_back(root->data);  // push this element in the vector

		return temp;
	}

	else{   // if value of root is greater than entered value

		bool temp = findPath(root->left, key, path);  // then search in LST

		if(temp == true)
		path.push_back(root->data);   // push this element in the vector

		return temp;
	}
}


vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	
	vector<int>* path = new vector<int>();  //  new vector to store the path from the node with value data to the root.

	if(findPath(root, data, *path) == true)
	return path;

	else{
	
	// If no path is found, delete the dynamically allocated vector and return NULL

		delete path;  // dynamically allocated path vector is deleted to free the memory
		
		return NULL;  // NULL to indicate that the node was not found.
	}

	
}
