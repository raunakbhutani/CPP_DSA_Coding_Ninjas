/*
You are given a ‘Binary Tree’.



Return the preorder traversal of the Binary Tree.
  */


/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void traverse(TreeNode<int>* node, vector<int>& result){  // helper function

// in preorder the root gets printed first then the data of its children

    if(node == NULL)
    return;

     result.push_back(node->data);  // first visit the root node

    traverse(node->left, result);  // traverse the left subtree
    
    traverse(node->right, result);  // traverse the right subtree


}

vector<int> preOrder(TreeNode<int> * root){

    vector<int> result;  // vector that holds the values of nodes in the order they are visited.

    traverse(root ,result);

    return result;

}

