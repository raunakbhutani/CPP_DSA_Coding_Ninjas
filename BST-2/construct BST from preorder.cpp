/*
Problem statement
You are given a preorder traversal of a binary search tree. Your task is to find the postorder from the preorder.



Return the root of the BST constructed from the given preorder. The driver code will then use this root to print the post-order traversal.
  */

/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*************************************************************/


#include <climits>

TreeNode* constructBSTfromPreorder(vector<int> &preOrder, int& index, int minVal, int maxVal) {

    // Base case: if all nodes are processed or current value is out of the allowed range
    if (index >= preOrder.size() || preOrder[index] < minVal || preOrder[index] > maxVal) 
        return NULL;
    

    // Create the root node with the current value
    int key = preOrder[index++];
    TreeNode* root = new TreeNode(key);

    // Construct the left subtree with updated maximum value
    // In a BST, all values in the LST must be less than the root value.
    // Therefore, we update maxVal to key for the left subtree while keeping minVal unchanged.

    root->left = constructBSTfromPreorder(preOrder, index, minVal, key);

    // Construct the right subtree with updated minimum value
    // in RST all values must be greater than root value
    // we upd8 minVal to key for RST 
    root->right = constructBSTfromPreorder(preOrder, index, key, maxVal);

    return root;
}

TreeNode* preOrderTree(vector<int> &preOrder) {
  
    int index = 0;
    return constructBSTfromPreorder(preOrder, index, INT_MIN, INT_MAX);
}
