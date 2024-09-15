/*
Problem statement
You have been given a Binary Search Tree of integers with ‘N’ nodes. You are also given data of a node of this tree. Your task is to delete the given node from the BST.


A binary search tree (BST) is a binary tree data structure that has the following properties:

• The left subtree of a node contains only nodes with data less than the node’s data.

• The right subtree of a node contains only nodes with data greater than the node’s data.

• Both the left and right subtrees must also be binary search trees.
  */


/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

     // func to loc8 the min value in in BST 

BinaryTreeNode<int>* findMin(BinaryTreeNode<int>* node) {
    
    // in BST smallest val is always loc8ed in leftmost node of tree

    while (node->left != NULL) {
        node = node->left;
    }
    
    return node;
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    if (root == NULL) 
    return root;
    

    if (key < root->data)   // if key data is less than root's data 
    root->left = deleteNode(root->left, key);   // recursively search left subtree
    
    else if (key > root->data)  // if key data is greater than root's data 
     root->right = deleteNode(root->right, key);   // recursively search right subtree
    
    else {
        // if the node to be deleted has only 1 child

        if (root->left == NULL) {   // if no left child 
            
            BinaryTreeNode<int>* temp = root->right;  // then return right child
            delete root;
            return temp;
        } 
        
        else if (root->right == NULL) {   // if no right child

            BinaryTreeNode<int>* temp = root->left;   // then return left child
            delete root;
            return temp;
        }
 
        // Node with two children: Get the inorder successor (smallest in the right subtree)

        BinaryTreeNode<int>* temp = findMin(root->right);   // root->right to find the minimum in the right subtree

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);   // Delete the inorder successor from the right subtree
    }
   
    return root;
}
