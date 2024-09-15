/*
Problem statement
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

Note:

1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
  */

#include <unordered_set>

void pairSum(BinaryTreeNode<int>* root, int sum) {
    if (root == NULL) {
        return;
    }

    unordered_set<int> complements;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<int>* current = q.front();
        q.pop();

        int currentData = current->data;
        int complement = sum - currentData;

        if (complements.find(currentData) != complements.end()) {
            cout << min(currentData, complement) << " " << max(currentData, complement) << endl;
        }

        complements.insert(complement);

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}
