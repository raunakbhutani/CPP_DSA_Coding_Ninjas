/*
Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.



Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.



For printing MST follow the steps -

1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note: Order of different edges doesn't matter.
  */

#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int findMinVertex(int *weights, bool *visited, int vertices) {

  int minVertex = -1; // initially there is no

  for (int i = 0; i < vertices; i++) {

    if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])) // if that vertex is unvisited AND its weight is less than weight of minVertex
      minVertex = i;              // set that vertex as minVertex
  }

  return minVertex;
}

void prims(int **edges, int V) {

  int *parent = new int[V];  // array to store weights of diff
  int *weights = new int[V]; // array to store weights of edges
  bool *visited =
      new bool[V]; // array to store which all vertices have been visited

  for (int i = 0; i < V; i++) {

    visited[i] = false;   // mark all the vertices as unvisited
    weights[i] = INT_MAX; // put weights as maximum
  }

  parent[0] = -1; // there is no parent of 1st elem
  weights[0] = 0; // the weight of 1st elem is 0

  for (int i = 0; i < V; i++) {

    int minVertex =
        findMinVertex(weights, visited, V); // find vertex with min weight
    visited[minVertex] = true; // mark minVertex as visited as we have found it

    for (int j = 0; j < V; j++) {

      if (!visited[j] &&
          edges[minVertex][j] != 0) { // if the vertex is unvisited AND there is an edge b/w that vertex & minVertex

        if (edges[minVertex][j] < weights[j]) { // if this is a better edge with min wt

          weights[j] = edges[minVertex][j]; // upd8 the edge
          parent[j] = minVertex;            // now parent becomes minVertex
        }
      }
    }
  }
  for(int i = 1; i < V; i++){    // print the MST

  if (parent[i] < i)
    cout << parent[i] << " " << i << " " << weights[i] << endl;

  else
    cout << i << " " << parent[i] << " " << weights[i] << endl;
}
}



int main() {

  int V, E;
  cin >> V >> E;

  int** edgesArray = new int*[V];  // create a 2D array for storing whether the path exists b/w those 2 vertices
	
	for(int i = 0; i < V; i++){  // traverse all the vertices
		
		edgesArray[i] = new int[V];  // storing 0/1 for whether a path exists or not
		
		for(int j = 0; j < V; j++){
			
			edgesArray[i][j] = 0;  // store each val as 0 in array
		}
	}
	
	
	for(int i = 0; i < E; i++){  // take I/P edges
		
		int firstVertex, secondVertex, weight;
		cin >> firstVertex >> secondVertex >> weight;
	
	// create an edge b/w firstVertex & secondVertex 
		edgesArray[firstVertex][secondVertex] = weight;   // & then make a connection b/w them
		edgesArray[secondVertex][firstVertex] = weight; 
	}
	
	prims(edgesArray, V);
	
	
	for(int i = 0; i < V; i++){
		
		delete[] edgesArray[i];
	}
	
	delete[] edgesArray;
}
