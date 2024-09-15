/*
Problem statement
Given a binary search tree and an integer.Find the floor value of a key in a binary search tree .

(If k lies in BST then is floor equal to k,else floor is equal to previous greater value) Note: k would never be less than the minimum element of tree.
  */

#include <climits>

int Floor(BinaryTreeNode<int> *node, int input)
{
		/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 

	int flr = INT_MIN;   // Initialize the floor value to a very small number
	
	while(node!=NULL){   // traverse the whole tree

		if(node->data == input)  // If the current node's value is equal to the key
		return node->data;   // then that is the floor

		else if(node->data < input){    // current node's value is less than the key,  
			
			flr=node->data;   // it means this node could be a potential floor value.  // We update the floor variable to the current node's value.

			node=node->right;  
		}

		else   // current node's value is greater than the key, we need to look for smaller values.
		node = node->left;   //  Thus, we move to the LST
	}

	return flr;
}
