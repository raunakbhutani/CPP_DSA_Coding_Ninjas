/*
Problem statement
Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).

Print the elements in increasing order.
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

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	// Write your code here

	if(root == NULL)
	return;

	if(k1 < root->data || k2 < root->data)  // if entered value is less than root's data then search in LST
	elementsInRangeK1K2(root->left, k1, k2);

	if(k1 <= root->data && k2 >= root->data)  // print the current node's value if it is within the range
	cout<<root->data<<" ";

	if(k2 > root->data || k1 > root->data)  // // if entered value is greater than root's data then search in RST
	elementsInRangeK1K2(root->right, k1, k2);
}
