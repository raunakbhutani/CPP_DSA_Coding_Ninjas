/*
Problem statement
You are given a generic tree. You have to replace each node with its depth value.
You just have to update the data of each node, there is no need to return or print anything.

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

void helper(TreeNode<int>* node, int depth){
    
    if(node == NULL)
    return;

    
    node->data = depth;

    for(int i=0; i<node->children.size(); i++){
        
        helper(node->children[i], depth + 1);
    }
}



void replaceWithDepthValue(TreeNode<int>* root) {

    helper(root, 0);
}
