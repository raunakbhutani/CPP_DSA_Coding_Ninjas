/*
Problem statement
Given a generic tree, count and return the number of leaf nodes present in the given tree.
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

int getLeafNodeCount(TreeNode<int>* root) {
    
    if(root==NULL)      // edge case
    return 0;

    if(root->children.size()==0)    // if there's only head node
    return 1;

    int leafCount=0;

    for(int i=0; i<root->children.size(); i++){
      
        leafCount+=getLeafNodeCount(root->children[i]);
    }
    
    return leafCount;
}
