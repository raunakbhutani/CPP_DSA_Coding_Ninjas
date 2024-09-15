/*
Problem statement
You have been given a binary search tree of integers with ‘N’ nodes. You are also given 'KEY' which represents data of a node of this tree.



Your task is to return the predecessor and successor of the given node in the BST.



Note:
1. The predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal of the tree. If the given node is visited first in the inorder traversal, then its predecessor is NULL.

2. The successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal of the tree. If the given node is visited last in the inorder traversal, then its successor is NULL.

3. The node for which the predecessor and successor will not always be present. If not present, you can hypothetically assume it's position (Given that it is a BST) and accordingly find out the predecessor and successor.

4. A binary search tree (BST) is a binary tree data structure which has the following properties.
     • The left subtree of a node contains only nodes with data less than the node’s data.
     • The right subtree of a node contains only nodes with data greater than the node’s data.
     • Both the left and right subtrees must also be binary search trees.
  */

/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    TreeNode* current = root;
    TreeNode* predecessor = NULL;
    TreeNode* successor = NULL;

    while(current != NULL){

        if(current->data == key){  // when the node with key is found then determine its predecessor & successor

        if(current->left != NULL){  // If the node has a left child

        TreeNode* temp = current->left;   

        while (temp->right != NULL) {

          temp = temp->right;
        }
            predecessor = temp;   // predecessor is the rightmost node in the left subtree.
        
        }

        if(current->right != NULL){  // if the node has right child

            TreeNode* temp = current->right;  

            while(temp->left != NULL){
                
                temp= temp->left;
            }
            successor = temp;
        }
        break;
        }

        else if(current->data < key){
            
            predecessor = current;
            current = current->right;
        }
        
        else{

            successor = current;
            current = current->left;
        }
    }
  
   
   // value of predeccessor
    int predVal ;
    if (predecessor != NULL) 
     predVal = predecessor->data ;
    
    else
        predVal=-1;
    
   
    // value of successor
    int succVal ;
    if (successor != NULL) 
        succVal=successor->data;
      
    else
        succVal=-1;
    

    return make_pair(predVal, succVal);
}
