/*
Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

Find the path using DFS and print the first path that you encountered.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
  */

#include <iostream>
#include <vector>
using namespace std;

vector<int> getPathDFS(int** edges, int vertices, int v1, int v2, bool* visited){

    visited[v1] = true;  // mark the staringVertex(v1) as visited(true)

    if(v1 == v2){  // if start & end vertex is same

        vector<int> temp;
        temp.push_back(v1);  // push that elem in vector
        return temp;
}

    vector<int> ans;  // vector to store the DFS path 

    for(int i = 0; i < vertices; i++){
        
        if(i == v1)  // if currentVertex is same as v1
        continue;

        if(edges[v1][i] && !visited[i]){  // if an edge exists b/w v1 & i AND also that vertex is unvisited

            ans = getPathDFS(edges, vertices, i, v2, visited);

            if(!ans.empty()){  // if there's a valid path

                ans.push_back(v1);  // 
                return ans;
            }
        }
    }

    return ans;
}


int main() {
    // Write your code here

    int V, E;  // enter total vertices & edges in graph
    cin >> V >> E;

    int** edgesArray = new int*[V];  // create a 2D array to store the edges

    for(int i = 0; i < V; i++){

        edgesArray[i] = new int[V];

        for(int j = 0; j < V; j++){

            edgesArray[i][j] = 0;  // initiallt mark all the indexes as 0
        }
    }
    
    for(int i = 0; i < E; i++){

        int firstVertex, secondVertex;
        
        cin >> firstVertex >> secondVertex;
        
// make a conncection b/w firstVertex & secondVertex
        edgesArray[firstVertex][secondVertex] = 1;
        edgesArray[secondVertex][firstVertex] = 1;
    }

    int v1, v2;  // I/P v1, v2 b/w which path is to be found
    cin >> v1 >> v2;

    bool* visited = new bool[V];  // array to keep check on all which all vertices have been visited

    for(int i = 0; i < V; i++){

        visited[i] = false;  // initially mark all of them as unvisited(false)
    }

    vector<int> path;  // vector to store the path from v1 to v2
    
    path = getPathDFS(edgesArray, V, v1, v2, visited);

    for(int i = 0; i < path.size(); i++){

        cout << path[i] << " ";
    }


    for(int i = 0; i < V; i++){

        delete [] edgesArray[i];
    }

    delete [] edgesArray;
    delete[] visited;
}
