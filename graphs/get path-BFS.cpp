/*
Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

Find the path using BFS and print the shortest path available.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
  */

#include <iostream>
#include<unordered_map>
#include <queue>
using namespace std;

void getPathBFS(int** edges, int vertices, int v1, int v2, bool* visited, unordered_map<int, int>& path){

// map for string the predecessor so that we could reconstruct the path from v1 to v2

    queue<int> q;  // for BFS traversasl make a queue to store the vertices
    q.push(v1);   // add the first elem in queue

    while(!q.empty()){

// take out the elem from queue & mark that visited to form a path
        int vertex = q.front();
        q.pop();
        visited[vertex] = true;
    

    if(vertex == v2)  // if we have reached the end vertex(v2)
    return;

    for(int i = 0; i < vertices; i++){

    if (edges[vertex][i] && !visited[i]){  // if there exists a path b/w vertex & i AND also that vertex'i' is unvisited

      q.push(i);   // push that vertex in the queue

      if (path.count(i) == 0)   // to prevent overwite of predecessor
        path[i] = vertex;
    }
    }
    }
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

// make a conncection b/w firstVertex & secondVertex
        edges[firstVertex][secondVertex] = 1;
        edges[secondVertex][firstVertex] = 1;
    }

    int v1, v2;  // input the vertices v1 and v2
    cin >> v1 >> v2;

    bool* visited = new bool[V];  // visited array to store all the visited vertices
    for(int i = 0; i < V; i++){

        visited[i] = false;  // initially mark all the vertices as unvisited(false)
    }

    unordered_map<int, int> path;
    getPathBFS(edges, V, v1, v2, visited, path);

    if(visited[v2] == true){  // if there's a valid path till v2

        int end = v2;  // store the last vertex(v2) in end
        
        while(end != v1){  // backtrack from v2 to v1

            cout << end << " ";  // print the path
            end = path[end];  // upd8 the end vertex
        }

        cout << end;  // finally add the first last vertex
    }


    for(int i = 0; i < V; i++){

        delete [] edges[i];
    }

    delete [] edges;
    delete [] visited;
}
