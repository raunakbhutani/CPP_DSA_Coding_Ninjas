/*
Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
  */

#include <iostream>
#include <queue>
using namespace std;

bool isExist(int** edges, int vertices, int v1, int v2, bool* visited){

    if(v1 == v2)  // if both the vertices are same
    return true;
    
    visited[v1] = true;  // mark the startingVertex(i.e v1) as visited

    if(edges[v1][v2] == 1)  // if v1 & v2 are directly connected to each other
    return true;

    

    for(int i = 0; i < vertices; i++){

        if(!visited[i] && edges[v1][i] == 1){  // check if 'i' is unvisited AND v1 & i have a connection b/w them

            if(isExist(edges, vertices, i, v2, visited))  // traverse for rest of the vertices staring from 'i'
            return true;
        } 

    }
    
    return false;  // if no path exists
}


int main() {
  
    int V, E;
    cin >> V >> E;

    int** edgesArray = new int*[V];  // create a 2D array to store the vertices 

// create an adjacency matrix
    for(int i = 0; i < V; i++){

        edgesArray[i] = new int[V];
        for(int j = 0; j < V; j++){

            edgesArray[i][j] = 0;  // first initialise the elem with 0 in the array
        }
    }

    for(int i =0; i < E; i++){  // I/P the vertices of the graph

        int v1, v2;
        cin >> v1 >> v2;

// create an edge b/w firstVertex & secondVertex
        edgesArray[v1][v2] = 1;
        edgesArray[v2][v1] = 1;
    }

    bool* visited = new bool[V];  // array to keep check on visited vertices
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    int v1, v2;
    cin >> v1 >> v2;

    bool result = isExist(edgesArray, V, v1, v2, visited);

    if(result == true)
    cout<<"true";

    else
    cout<<"false";

    for(int i = 0; i < V; i++){
        
        delete[] edgesArray[i];
    }

    delete[] edgesArray;
    delete[] visited;
}
