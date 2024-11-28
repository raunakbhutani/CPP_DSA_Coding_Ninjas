/*
Problem statement
Given an undirected and disconnected graph G(V, E), print its BFS traversal.

Note:

1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well
*/

#include <iostream>
#include <queue>
using namespace std;

void printBFS(int** edges, int vertices, int startingVertex, bool* visited){  // print vertices level wise i.e BFS

  queue<int> pendingVertices;  // queue of seen vertices but not printed yet

  pendingVertices.push(startingVertex); // add the startingVertex to the queue
  visited[startingVertex] = true;       // & mark it as true(visited)

  while (!pendingVertices.empty()) {
    // first pop the first elem from the queue

    int currentVertex = pendingVertices.front();
    pendingVertices.pop();

    cout << currentVertex << " ";  // now print the currentVertex

    for (int i = 0; i < vertices; i++) {  // traverse all the vertices
      
        if (i == currentVertex) // we r not checking if 0 has edge with itself
          continue;

         if (edges[currentVertex][i] == 1 && !visited[i]){  // check if there's an edge b/w currentvertex & i AND also if that array is unvisited

            pendingVertices.push(i);  // then push elements in queue 
            visited[i] = true;  // & mark them as true(visited)
      }
    }
  }

}

void BFS(int** edges, int vertices){

    bool* visited = new bool[vertices];  // visited array for storing the visited elem

    for(int i = 0; i < vertices; i++){
      
      visited[i] = false;  // first mark all of them as unvisited(false)
    }

    for(int i = 0; i < vertices; i++){  // traverse all the edges even if graph is disconnected

      if(!visited[i])  // if that vertex is unvisited
      printBFS(edges, vertices, i, visited);  // start printing from that idx
    }

    delete[] visited;
}

int main() {
  // Write your code here

    int V, E;  
    cin >> V >> E;  // I/P the vertices & edges


    int** edgesArray = new int*[V];  // create a 2D array for storing the paths
    
    for(int i = 0; i < V; i++){

        edgesArray[i] = new int[V];  

        for(int j = 0; j < V; j++){  // initially mark all the cells unvisited 

            edgesArray[i][j] = 0;
        }
    }

    for(int i = 0; i < E; i++){  // I/P all the edges

        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;
    
// make a connection b/w firstVertex & secondVertex
        edgesArray[firstVertex][secondVertex] = 1;
        edgesArray[secondVertex][firstVertex] = 1;
    }


   BFS(edgesArray, V);

    for(int i = 0; i < V; i++){

        delete[] edgesArray[i];
    }

    delete[] edgesArray;
    
}
