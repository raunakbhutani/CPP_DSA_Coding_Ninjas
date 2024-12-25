/*
Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.

For printing MST follow the steps -

1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class edge{  
	
	public:
		int source;
		int dest;
		int weight;
};


bool compare(edge e1, edge e2){
	
	return e1.weight < e2.weight;  // to sort in ascending order
}


int findParent(int vertex, int* parent){
	
	if(parent[vertex] == vertex)  // if elem & index are same
	return vertex;
			
	return findParent(parent[vertex], parent);
}



void kruskals(edge* input, int V, int E){
	
	sort(input, input + E, compare);  
	
	edge* output = new edge[V - 1];  // array to store the MST elem

	int* parent = new int[V];  // to store the parent elem of each vertex
	for(int i = 0; i < V; i++){
		
		parent[i] = i;  // every vertex is parent of itself
	}
	
	int count = 0;  // tell how much edges have been added in our MST
	int i = 0;  // to tell on which elem we are working
	
	while(count != V - 1){  // main like how to create an MST
		
		edge currentEdge = input[i];
		
		// variables to find the topmost parent of this elem
		int sourceParent = findParent(currentEdge.source, parent);
		int destParent = findParent(currentEdge.dest, parent);
		
		if(sourceParent != destParent){  // this edge is safe to add
		
			output[count] = currentEdge;  // add currentEdge in output 
			count++;
			
			parent[sourceParent] = destParent;  // destParent becomes the parent of sourceParent
		}
		i++;
		
	}
	
	for(int i = 0; i < V - 1; i++){  // now print the MST
		
		if(output[i].source < output[i].dest)
		cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
		
		else
		cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
	}
}


int main() {
    // Write your code here
    int V, E;
	cin >> V >> E;

	edge* input = new edge[E];
	
	for(int i = 0; i < E; i++){
		
		int s, d, w;
		cin >> s >> d >> w;
		
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	
	kruskals(input, V, E);
}
