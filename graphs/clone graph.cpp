/*
Problem statement
You are given a reference/address of a node in a connected undirected graph containing N nodes and M edges. You are supposed to return a clone of the given graph which is nothing but a deep copy. Each node in the graph contains an integer “data” and an array/list of its neighbours.

The structure of the graphNode class is as follows:

class graphNode 
{  
    public:
        int data;
        vector<graphNode*> neighbours;
}
Note :
1. Nodes are numbered from 1 to N.

2. Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
  */

#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraph(graphNode *node){
   if (!node) return nullptr; // Handle edge case when node is null

    // Map to store the original node to its corresponding cloned node
    unordered_map<graphNode*, graphNode*> m;
    queue<graphNode*> q;

    // Initialize by pushing the source node
    q.push(node);

    // Create the clone of the source node
    graphNode* srcClone = new graphNode(node->data);

    // Store this in the map
    m[node] = srcClone;

    // Perform BFS to traverse the graph
    while (!q.empty()) {
        graphNode* curr = q.front();
        q.pop();

        // Traverse all neighbours of the current node
        for (graphNode* neighbor : curr->neighbours) {
            // If the neighbour has not been cloned yet
            if (m.find(neighbor) == m.end()) {
                // Clone and map it
                m[neighbor] = new graphNode(neighbor->data);
                // Push the neighbor node into the queue for future traversal
                q.push(neighbor);
            }
            // Link the clone of the current node to the clone of its neighbours
            m[curr]->neighbours.push_back(m[neighbor]);
        }
    }

    // Return the clone of the original source node
    return m[node];
}

// Helper function to compare two graphs
bool compareGraphs(graphNode* node1, graphNode* node2, unordered_map<graphNode*, bool>& visited) {
    if (!node1 || !node2) return node1 == node2; // Both should be null

    if (node1->data != node2->data) return false; // Data mismatch

    visited[node1] = true;

    // Compare the size of the neighbours
    if (node1->neighbours.size() != node2->neighbours.size()) return false;

    for (int i = 0; i < node1->neighbours.size(); i++) {
        graphNode* n1 = node1->neighbours[i];
        graphNode* n2 = node2->neighbours[i];

        // If a neighbour hasn't been visited, compare recursively
        if (!visited[n1]) {
            if (!compareGraphs(n1, n2, visited)) return false;
        }
    }

    return true;
}

// Function to check if the original graph and its clone are identical
bool areGraphsIdentical(graphNode *original, graphNode *clone) {
    unordered_map<graphNode *, bool> visited;
    return compareGraphs(original, clone, visited);
}
