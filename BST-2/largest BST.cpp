/*
Problem statement
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.

Note :
The binary tree will be consisting of only unique elements.
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
#include <climits>

struct info{

	int minVal;
	int maxVal;
	int height;
	bool isBST;
};

info largestBSTSubtreehelper(BinaryTreeNode<int> *root, int& maxHeight){

	if(root == NULL)  // empty tree is of height 0
	return{INT_MAX, INT_MIN, 0, true};


	info leftInfo = largestBSTSubtreehelper(root->left, maxHeight);
	info rightInfo = largestBSTSubtreehelper(root->right, maxHeight);

	// current node

	info current;
	
	current.minVal = min(root->data, leftInfo.minVal);

	current.maxVal = max(root->data, rightInfo.maxVal);

	current.height = max(leftInfo.height, rightInfo.height) + 1;

	// check if the current node is BST
        if (leftInfo.isBST && rightInfo.isBST && root->data > leftInfo.maxVal &&
            root->data < rightInfo.minVal) {
        current.isBST = true;
        // Update the maximum height if this subtree is the largest BST found so
        // far
        maxHeight = max(maxHeight, current.height);
        }

		else
		current.isBST = false;

		return current;
}


int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	int maxHeight = 0;
	
	largestBSTSubtreehelper(root, maxHeight);

	return maxHeight;
	
}
