/*
Problem statement
You are given a Binary Search Tree.



Find the minimum value in it.

*/

/*
 * class Node
 * {
 * public:
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node() : data(0), left(nullptr), right(nullptr){};
 *     Node(int x) : data(x), left(nullptr), right(nullptr) {}
 *     Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
 * };
 */
int minVal(Node* root){
	// Write your code here.

	if(root == NULL)	
	return -1;

	Node* current = root;  
	
	while(current->left != NULL){  // min value will be found in left subtree
		current = current->left;
	}

	return current->data;

}
