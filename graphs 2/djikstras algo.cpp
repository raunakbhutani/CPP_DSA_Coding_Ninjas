/*
Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int findMinVertex(int* distance, bool* visited, int vertices){
	
	int minVertex = -1;  // initially there is no vertex
	
	for(int i = 0; i < vertices; i++){
		
		if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))  // if the vertex is unvisited AND if the i has minPath as comp to minVertex
		minVertex = i;  // then set minVertex as that vertex
	} 
	
	return minVertex;
}



void djikstra(int** edges, int vertices){
	
	int* distanceArray = new int[vertices];  // array to store the min distance b/w vertices
	bool* visited = new bool[vertices];  // array to store visited vertices
	
	for(int i = 0; i < vertices; i++){
		
		distanceArray[i] = INT_MAX;
		visited[i] = false;
	}
	
	distanceArray[0] = 0;  // mark the source vertex distance as 0
	
	for(int i = 0; i < vertices; i++){
		
		int minVertex = findMinVertex(distanceArray, visited, vertices);  // vertex with min path b/w 2 edges
		visited[minVertex] = true;
		
		for(int j = 0; j < vertices; j++){  // traverse the adjacency matrix
			
			if(!visited[j] && edges[minVertex][j] != 0){  // if that vertex is unvisited AND there exists a path b/w minVertex & j
				
				int dist = distanceArray[minVertex] + edges[minVertex][j];  // distance is sum of source to minVertex + till that final vertex till where u wanna go
				if(dist < distanceArray[j])  // if curent distance > distance then,
				distanceArray[j] = dist;  // set  current distance in distanceArray
			}
		}
	}
	
	for(int i = 0; i < vertices; i++){  // print the min path 
		
		cout << i << " " << distanceArray[i] << endl;
	}
	
	delete[] visited;
	delete[] distanceArray;
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
		edgesArray[firstVertex][secondVertex] = weight;   // & set there weight 
		edgesArray[secondVertex][firstVertex] = weight; 
	}
	
	djikstra(edgesArray, V);
	
	
	for(int i = 0; i < V; i++){
		
		delete[] edgesArray[i];
	}
	
	delete[] edgesArray;
}
