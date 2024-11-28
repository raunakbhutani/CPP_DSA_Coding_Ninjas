/*
Problem statement
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group .
  Given V islands (numbered from 0 to V-1) and E connections or edges between islands. Can you count the number of connected groups of islands.
  */

#include <iostream>
using namespace std;

void DFS(int** edges, int vertices, int startIsland, bool* visited){

    visited[startIsland] = true;  // mark the firstisland as connected

    for(int i = 0; i < vertices; i++){

        if(edges[startIsland][i] == 1 && !visited[i])
        DFS(edges, vertices, i, visited);
    }
}


int countIslands(int** edges, int vertices){

    bool* visited = new bool[vertices];

    for(int i = 0; i < vertices; i++){

        visited[i] = false;
    }

    int count = 0;  // to count the no of connected gp of islands

    for(int i = 0; i < vertices; i++){

        if(!visited[i] == true){  // if that island is unvisited

            count++;  // increment the count 
            DFS(edges, vertices, i, visited);
        }
    }

    delete [] visited;
    
    return count;
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

        int firstIsland, secondIsland;
        cin >> firstIsland >> secondIsland;
        
        edges[firstIsland][secondIsland] = 1;
        edges[secondIsland][firstIsland] = 1;
    }

    int ans = countIslands(edges, V);
    cout << ans;

    for(int i = 0; i < V; i++){

        delete[] edges[i];
    }
    
    delete[] edges;
}
