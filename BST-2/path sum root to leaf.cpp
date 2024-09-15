/*
Problem statement
For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.
  */


#include<vector>
#include<algorithm>

void printPath(const vector<int>& path){

	for(int i=0; i<path.size(); i++){
		cout<<path[i];
		
		if(i!=path.size() - 1)
		cout<<" ";
	}
	
	cout<<endl;
}

void findPath(BinaryTreeNode<int> *root, int k, vector<int>& path){

	if(root == NULL)
	return;

	path.push_back(root->data);   // add the current node to path

	if(root->left == NULL && root->right == NULL && root->data == k)  // if we reach leaf node & cuurent node is equal to required sum(k)
	printPath(path);

	findPath(root->left, k - root->data, path);
	findPath(root->right, k - root->data, path);

	path.pop_back();  // Backtrack: remove the current node from the path if it was not the coorect path that equals sum(k)
}


void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    
	vector<int> path;
	findPath(root, k, path);

}
