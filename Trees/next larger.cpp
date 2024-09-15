/*
Problem statement
Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.

Note: Return NULL if no node is present with the value greater than n.
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

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {

    if(root == NULL)   // base case
    return NULL;

    TreeNode<int>* result = NULL;

    if(root->data > x)
     result = root;

    for(int i=0; i<root->children.size(); i++){
        // recursion to check for all children
        TreeNode<int>* childResult = getNextLargerElement(root->children[i],x);

        // upd8 the result 
        if(childResult!=NULL && (result==NULL || childResult->data < result->data))
        result = childResult;
    }


    return result;

}
