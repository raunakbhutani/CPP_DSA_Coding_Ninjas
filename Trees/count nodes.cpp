/*
Problem statement
Given a tree and an integer x, find and return the number of nodes which contains data greater than x.
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

int getLargeNodeCount(TreeNode<int>* root, int x) {
    
    if(root==NULL)
    return 0;

    int count=0;
    if(root->data>x)
    count++;

    for(int i=0; i<root->children.size(); i++){
      
        count+=getLargeNodeCount(root->children[i],x);
    }
  
    return count;
}
