/*
Problem statement
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
  */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void connected(int** edges, vector<int>& ans, int vertices, int startVertex, bool* visited){

    ans.push_back(startVertex);  // push the startVertex in vector
    visited[startVertex] = true;  // mark startVertex as visited(true)

    for(int i = 0; i < vertices; i++){

        if(i == startVertex)  // we don't want to check edge b/w 0 & 0
        continue; 

        if(edges[startVertex][i] && !visited[i])  // if there's an edge & that vertex is unvisited
        connected(edges, ans, vertices, i, visited);
    }
}

void print(vector<vector<int> >& result){  
    // we are returning the vector of vector of connected of comp

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){

            cout << result[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {


    int V, E;
    cin >> V >> E;

    int** edges =  new int*[V];
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

    bool* visited = new bool[V];
    for(int i = 0; i < V; i++){

        visited[i] = false;
    }

    vector<vector<int> > ans;
    vector<int> temp;  //  temp vector to store connected comp

    for(int i = 0; i < V; i++){

        if (!visited[i]) {

            temp.clear();  // we are clearing the temp vector to store next set of connected comp
            connected(edges, temp, V, i, visited);
            sort(temp.begin(), temp.end());
            
            ans.push_back(temp);  // add that part comp to the ans vector
            
        }
    }

    print(ans);

    for(int i = 0; i < V; i++){

        delete [] edges[i];
    }

    delete [] edges;
    delete [] visited;
}
