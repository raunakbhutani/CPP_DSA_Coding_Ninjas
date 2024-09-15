/*
Problem statement
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists.
You just need to construct the tree and return the root.

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

#include <unordered_map>

BinaryTreeNode<int>* buildTreeHelper(int* postorder, int postStart, int postEnd, int* inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
   
    if (postStart > postEnd || inStart > inEnd) 
        return NULL;
    
	int rootVal = postorder[postEnd];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootVal);
    int inIndex = inorderMap[rootVal];

    int numsLeft = inIndex - inStart;

    root->left = buildTreeHelper(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inIndex - 1, inorderMap);
    root->right = buildTreeHelper(postorder, postStart + numsLeft, postEnd - 1, inorder, inIndex + 1, inEnd, inorderMap);

    return root;
}

BinaryTreeNode<int> *buildTree(int *postorder, int postLength, int *inorder,int inLength) {
  // Write your code here

	if (postLength != inLength || postLength == 0) {
        return NULL;
    }

    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inLength; ++i) {
        inorderMap[inorder[i]] = i;
    }

    return buildTreeHelper(postorder, 0, postLength - 1, inorder, 0, inLength - 1, inorderMap);
}

// Helper function to print the tree in preorder for verification

    void printPreorder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
      
    printPreorder(root->left);
      
    printPreorder(root->right);
}



