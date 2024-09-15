/*
Problem statement
Given a generic tree, print the post-order traversal of given tree.

The post-order traversal is: visit child nodes first and then root node.
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

void printPostOrder(TreeNode<int>* root) {

// here first the data of children of root gets printed
    if(root ==NULL)
    return;

    for(int i=0; i<root->children.size(); i++){
      
        printPostOrder(root->children[i]);
    }

    // at last the root gets printed
    cout << root->data << " ";
}
