/*
Problem statement
Given a generic tree, find and return the height of given tree.
The height of a tree is defined as the longest distance from root node to any of the leaf node. Assume the height of a tree with a single node is 1.
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

int getHeight(TreeNode<int>* root) {

    if(root==NULL)
    return 0;

    int maxChildheight=0;

// loop that iterates over all the children of the current node (root).
    for(int i=0;i<root->children.size();i++){  
        int childHeight = getHeight(root->children[i]);

        if(childHeight > maxChildheight)
        maxChildheight = childHeight;
    }
    return maxChildheight+1;
}
