/*
Problem statement
Given a generic tree, find and return the sum of all nodes present in the given tree.
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

int sumOfNodes(TreeNode<int>* root) {
    // Write your code here

    if(root==NULL)  // edge case
    return 0;
    
    int sum=root->data;   // first start with the data of root node

    for(int i=0;i<root->children.size();i++){
        sum+=sumOfNodes(root->children[i]);  // keep on adding the data of children node to root data node
    }
    return sum;
}
