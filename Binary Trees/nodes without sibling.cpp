/*
Problem statement
For a given Binary Tree of type integer, print all the nodes without any siblings.

Example Input :
1 4 5 6 -1 -1 7 20 30 80 90 -1 -1 -1 -1 -1 -1 -1 -1
  */

/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {

// sibling is that which has only 1 child node
// we have to print the data of that child node

    if(root == NULL)
    return;

    if(root->left != NULL && root->right == NULL)  // if there is node w/o sibling only in left part
    cout<<root->left->data<<" ";

    if(root->left == NULL && root->right != NULL) // if there is node w/o sibling only in right part
    cout<<root->right->data<<" ";

    printNodesWithoutSibling(root->left);  
    printNodesWithoutSibling(root->right);


}
