/*
Problem statement
Given a generic tree, find and return the node with second largest value in given tree.

Note: Return NULL if no node with required value is present.
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

void findLargestAndgetSecondLargest(TreeNode<int>* root, TreeNode<int>** largest, TreeNode<int>** Secondlargest){
    
    if(root == NULL)
    return;

    if(*largest == NULL || root->data > (*largest)->data){  // upd8 largest & Secondlargest

        *Secondlargest = *largest;

        *largest = root;
    }

 else if ( (*Secondlargest == NULL || root->data > (*Secondlargest)->data) && root->data < (*largest)->data) 
        *Secondlargest = root;
    

    for(int i=0; i<root->children.size(); i++){
        
        findLargestAndgetSecondLargest(root->children[i], largest, Secondlargest);
    }

}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    
    if(root == NULL)
    return NULL;

    TreeNode<int>* largest = NULL;
    TreeNode<int>* Secondlargest = NULL;

    // find the largest & Secondlargest nodes
    findLargestAndgetSecondLargest(root, &largest, &Secondlargest);

    return Secondlargest;
}
