/*
Problem statement
Given an undirected graph G(V,E), check if the graph G is connected graph or not.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
  */

#include <iostream>
using namespace std;

void printDFS(int** edges , int vertices, int startVertex, bool* visited){

    visited[startVertex] = true;

    for(int i = 0; i < vertices; i++){

        if(edges[startVertex][i] == 1 && !visited[i])  
        printDFS(edges, vertices, i, visited);  // perform a DFS traversal 
    }
}


bool isConnected(int** edges, int vertices){

     bool* visited = new bool[vertices];

     for(int i = 0; i < vertices; i++){  

        visited[i] = false;  // initialise all vertices as unvisited
    }

    printDFS(edges, vertices, 0, visited); 

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {  // if there's any vertex that is unvisited 
        
        delete [] visited;
        return false;  // means graph is disconnected
        }
    }
    
    delete [] visited;
    return true;
}

int main() {
  
    int V, E;
    cin >> V >> E;

    int** edges = new int*[V];
    for(int i = 0; i < V; i++){

        edges[i] = new int[V];
        
        for(int j = 0; j < V; j++){

            edges[i][j] = 0;
        }
 }

    for(int i = 0; i < E; i++){

        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;

        edges[firstVertex][secondVertex] = 1;
        edges[secondVertex][firstVertex] = 1;
    }

    if(isConnected(edges, V) == true)
    cout << "true";

    else
    cout << "false";

    for(int i = 0; i < V; i++){

        delete [] edges[i];
    }

    delete [] edges;
    
}
