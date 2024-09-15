/*
Problem statement
For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.
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

bool isNodePresent(BinaryTreeNode<int> *root, int x) {

     if (root == NULL) 
     return false;

    queue<BinaryTreeNode<int>*> pendingNodes;  
    
    pendingNodes.push(root);  // root is added to the queue first to start the traversal

// breadth-first search (BFS). BFS is chosen here to check each level of the tree one by one.
    while (!pendingNodes.empty()) {
    
    BinaryTreeNode<int>* currentNode = pendingNodes.front();
    pendingNodes.pop();

    if (currentNode->data == x) {
        return true;
    }

    if (currentNode->left != NULL)   // If currentNode has a left child (currentNode->left != NULL), this left child is added to the queue.
        pendingNodes.push(currentNode->left);
    

    if (currentNode->right != NULL)  // if currentNode has a right child (currentNode->right != NULL), this right child is added to the queue.
        pendingNodes.push(currentNode->right);
    
}

    return false;  // if x is not found in the whole tree
}
