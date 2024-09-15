/*
Problem statement
For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line.
Elements on every level will be printed in a linear fashion and a single space will separate them.
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

	if(root == NULL)
	return;

	queue<BinaryTreeNode<int>*> q;
	
	q.push(root);
	q.push(NULL);    // marker for end of level

	while(!q.empty()){
		BinaryTreeNode<int>* front = q.front();
		q.pop();

		if(front == NULL){  // it indicates end of tree level

			cout<<endl;
			if(!q.empty())
			q.push(NULL);   // another NULL marker is added to the queue to indicate the end of the next level.
		}

		else{  // if front element is not NULL

			cout<<front->data<<" ";

			if(front->left!=NULL)
			q.push(front->left);

			if(front->right!=NULL)
			q.push(front->right);
		}
	}
}
