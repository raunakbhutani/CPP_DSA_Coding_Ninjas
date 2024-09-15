/*
Problem statement
Given two generic trees, return true if they are structurally identical. Otherwise return false.

Structural Identical
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called identical.  
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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    
    if(root1==NULL && root2==NULL)
    return true;

    if(root1==NULL || root2==NULL)
    return false;
    
// check if no of children is same
    if(root1->children.size() != root2->children.size())
    return false;

// traverse along the children of root1
    for(int i=0; i<root1->children.size(); i++){

        if(!areIdentical(root1->children[i], root2->children[i]))
        return false;
    }

    return true;


}
