/*
Problem statement
Given a BST and an integer K, you need to find the Kth smallest element present in the BST. Return INT_MIN if that is not present in the BST.
  */

#include <climits>
#include<vector>

void inorder(vector<int>& v, BinaryTreeNode<int>* root){

// we are storing the elements of BST in vector in sorted manner bcos of inorder traversal
	if(root == NULL)
	return;

	inorder(v, root->left);

	v.push_back(root->data);
	
	inorder(v, root->right);
}

int findNode(BinaryTreeNode<int>* root, int k) {


	vector<int> traversal;
	inorder(traversal, root);

	if(traversal.size() < k-1)  // out of range
	return INT_MIN;

	return traversal[k-1];  // returning the kth smallest element's data

}
