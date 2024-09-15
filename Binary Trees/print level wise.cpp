/*
Problem statement
For a given a Binary Tree of type integer, print the complete information of every node, when traversed in a level-order fashion.

To print the information of a node with data D, you need to follow the exact format :

           D:L:X,R:Y

Where D is the data of a node present in the binary tree. 
X and Y are the values of the left(L) and right(R) child of the node.
Print -1 if the child doesn't exist.
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

void printLevelWise(BinaryTreeNode<int> *root) {

	if(root == NULL)	// edge case
	return;

	queue<BinaryTreeNode<int>*> pendingNodes;  // make a queue to store the rest of the nodes
	
	pendingNodes.push(root);  // keep on pushing the nodes in queue 

	while(!pendingNodes.empty()){

		BinaryTreeNode<int>* queueFront = pendingNodes.front();
		pendingNodes.pop();

		cout<<queueFront->data<<":";   // first print root data

		if(queueFront->left != NULL){
      
			cout<<"L"<<":"<<queueFront->left->data<<",";
			pendingNodes.push(queueFront->left);
		}

		else
			cout<<"L"<<":"<<"-1"<<",";

		
		if(queueFront->right != NULL){
      
			cout<<"R"<<":"<<queueFront->right->data;
			pendingNodes.push(queueFront->right);
		}
		
		else
			cout<<"R"<<":"<<"-1";
		
		cout<<endl;
	}
}




