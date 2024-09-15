/*
Problem statement
Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.

Return null if tree is empty.
  */

/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
#include <vector>
#include <queue>

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
 
    if(root==NULL)    // edge case
    return NULL;

    TreeNode<int>* maxNode=root;  // initialise maxNode with root node

    for(int i=0;i<root->children.size();i++){  // Iterate through all the children of the root node
        
        TreeNode<int>* ChildmaxNode = maxDataNode(root->children[i]);

        // Compare the data of the current childMaxNode with maxNode
        if(ChildmaxNode!=NULL && ChildmaxNode->data > maxNode->data)
        
        maxNode = ChildmaxNode;  // Update maxNode if the child's data is greater
    }
   
    return maxNode;
}
