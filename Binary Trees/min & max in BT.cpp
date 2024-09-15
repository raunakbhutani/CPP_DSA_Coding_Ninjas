/*
Problem statement
For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.

Return the output as an object of Pair class, which is already created.

Note:
All the node data will be unique and hence there will always exist a minimum and maximum node data.
  */

/**********************************************************

        Following is the Binary Tree Node class structure

        template <typename T>
        class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
        };

***********************************************************/

/*
        The first value of the pair must be the minimum value in the tree and
        the second value of the pair must be the maximum value in the tree
*/
#include<climits>


pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
 
  if (root == NULL) {

    pair<int,int> p;

    p.first = INT_MAX;  // INT_MAX for the minimum to ensure that it does not incorrectly affect the minimum value of the entire tree.
    
    p.second = INT_MIN; // INT_MIN is used for the maximum to ensure any real data value will be larger and update the maximum correctly.

    return p;
  }

  pair<int,int> leftPair = getMinAndMax(root->left);  // traverse left part of tree
  
  pair <int,int> rightPair = getMinAndMax(root->right);  // traverse right part of tree

  pair<int,int> result;

  result.first = min(root->data, min(leftPair.first, rightPair.first));  // find out the min value  
  
  result.second = max(root->data, max(leftPair.second, rightPair.second));  // find out the max value

  return result;

}
