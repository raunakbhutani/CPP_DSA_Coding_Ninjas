/*
Problem statement
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum.
In the sum, data of the node and data of its immediate child nodes has to be taken.
  */

/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/




// this func will return the maxSum of root & its children
int SumofNodeAndchildren(TreeNode<int>* node){
    
    int sum = node->data;

    for(int i=0; i<node->children.size();i++){
        sum+=node->children[i]->data;
    }
    return sum;
}

// func to find the Node with maxSum
TreeNode<int>* maxSumNode(TreeNode<int>* root){
  
    if(root==NULL)
    return NULL;

    TreeNode<int>* maxNode = root;
    int maxSum= SumofNodeAndchildren(root);

    for(int i=0; i<root->children.size();i++){
        
        TreeNode<int>* childMaxNode = maxSumNode(root->children[i]);
        int childMaxSum = SumofNodeAndchildren(childMaxNode);

        if (childMaxSum > maxSum) {
          maxNode = childMaxNode;
          maxSum = childMaxSum;
        }
    }
  
    return maxNode;
}
