/*
Problem statement
You have been given a root node of the binary search tree and a positive integer value.
You need to perform an insertion operation i.e. inserting a new node with the given value in the given binary search tree such that the resultant tree is also a binary search tree.

If there can be more than one possible tree, then you can return any.

Note :

A binary search tree is a binary tree data structure, with the following properties :

    a. The left subtree of any node contains nodes with a value less than the node’s value.

    b. The right subtree of any node contains nodes with a value equal to or greater than the node’s value.

    c. Right, and left subtrees are also binary search trees.
It is guaranteed that,

    d. All nodes in the given tree are distinct positive integers.

    e. The given BST does not contain any node with a given integer value.

*/

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left, *right;
        TreeNode() : val(0), left(NULL), right(NULL) {}
        TreeNode(T x) : val(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right) {}
    };


************************************************************/

TreeNode<int>* insertionInBST(TreeNode<int>* root, int val){

    if(root == NULL)
    return new TreeNode(val);  // if tree is empty then create a new node as root 

    if(root->val < val){  // if entered val is greater than root data

         root->right = insertionInBST(root->right, val);  // then insert in right subtree
        
    }

    else{   // if entered value is less than root data

        root->left = insertionInBST(root->left, val);  // then insert in left subtree
        
    }
  
return root;
  
}
Below the tree is not a BST as node ‘2’ is less than node ‘3’ but ‘2’ is the right child of ‘3’, and node ‘6’ is greater than node ‘5’ but it is in the left subtree of node ‘5’.
*/

