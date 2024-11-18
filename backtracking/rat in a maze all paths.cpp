/*

Problem statement
You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print all paths that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. Rat can move in any direc­tion ( left, right, up and down).

Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked means the rat can­not enter into those cells and those with value 1 are open.
  */

#include <bits/stdc++.h> 
#include<vector>
void findPaths(vector<vector<int>>& maze, int n , int x, int y, vector<vector<int>>& visited, vector<vector<int>>& solutions){

 visited[x][y] = 1;  // mark the current cell as visited
// base case: if we have reached the desired location

  if(x == n - 1 && y == n - 1){

    vector<int> path;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){

       path.push_back(visited[i][j]);
      }
    }
    visited[x][y] = 0;  // mark the current cell as visited

    solutions.push_back(path);
    
    return;
  }

  

  if (x + 1 < n && maze[x + 1][y] == 1 && visited[x + 1][y] == 0) 
        findPaths(maze, n, x + 1, y, visited, solutions);
    

    // Move Left
    if (y - 1 >= 0 && maze[x][y - 1] == 1 && visited[x][y - 1] == 0) 
        findPaths(maze, n, x, y - 1, visited, solutions);
    

    // Move Right
    if (y + 1 < n && maze[x][y + 1] == 1 && visited[x][y + 1] == 0) 
        findPaths(maze, n, x, y + 1, visited, solutions);
    

    // Move Up
    if (x - 1 >= 0 && maze[x - 1][y] == 1 && visited[x - 1][y] == 0) 
        findPaths(maze, n, x - 1, y, visited, solutions);
    

    visited[x][y] = 0;  // Backtrack: Unmark the current cell as visited

}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
vector<vector<int>> visited(n, vector<int>(n, 0));  // Visited matrix to track the path
    vector<vector<int>> solutions;  // Store all valid paths in a binary format

    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
        // If the start or destination is blocked, return without any solution
        return solutions;
    }

    // Find all paths from (0,0) to (n-1,n-1)
    findPaths(maze, n, 0, 0, visited, solutions);

    return solutions;
  
}
