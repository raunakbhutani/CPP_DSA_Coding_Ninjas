/*
Problem statement
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on.
This means odd levels should get printed from left to right and even level right to left.
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
#include<algorithm>
#include<stack>

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root == NULL)
	return;

	stack<BinaryTreeNode<int>*> currLevel;
	stack<BinaryTreeNode<int>*> nextLevel;

	bool leftToright = true;

	currLevel.push(root);

	while(!currLevel.empty()){
		
		BinaryTreeNode<int>* node = currLevel.top();
		currLevel.pop();

		if(node)
		cout<<node->data<<" ";

		if(leftToright == true){ // If leftToRight is true, add the left child first, then the right child.
			
			if(node->left)
			nextLevel.push(node->left);

			if(node->right)
			nextLevel.push(node->right);
		}
		else{   // If leftToRight is false, add the right child first, then the left child.

			if(node->right)
			nextLevel.push(node->right);

			if(node->left)
			nextLevel.push(node->left);
		}

		if(currLevel.empty()){

			leftToright=!leftToright;  //  traversal direction is toggled by negating leftToRight.

			swap(currLevel, nextLevel);  // stacks currentLevel and nextLevel are swapped to start processing the next level.

			cout<<endl;
		}
	}
}
