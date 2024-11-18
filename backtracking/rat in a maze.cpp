/*
Problem statement
You are given a N*N maze with a rat placed at maze[0][0]. Find whether any path exist that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).

Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
*/

#include <iostream>
using namespace std;


bool vis[100][100];  // Array to keep track of cells already visited


bool cell[100][100];  // Array for path taken by rat (where true indicates a valid cell to move to)


bool isValid(int row, int col, int n) {   // Function to check if a move is valid

    // Check boundaries and if the cell is already visited or blocked
    if (row < 0 || row >= n || col < 0 || col >= n) 
        return false;
    
    if (vis[row][col] || cell[row][col] == false) 
        return false;
    

    return true;
}

// Recursive function to find a path from (row, col) to (n-1, n-1)
bool f(int row, int col, int n) {

   
    if (row == n - 1 && col == n - 1)   // Base case: Reached the last cell
        return true;
    

    vis[row][col] = true;   // Mark the cell as visited


    if (isValid(row, col - 1, n) == true) {  // Left
        if (f(row, col - 1, n)) 
            return true;
        
    }
    if (isValid(row, col + 1, n) == true) {  // Right
        if (f(row, col + 1, n)) 
            return true;
        
    }
    if (isValid(row - 1, col, n) == true) {  // Up
        if (f(row - 1, col, n)) 
            return true;
        
    }
    if (isValid(row + 1, col, n) == true) {  // Down
        if (f(row + 1, col, n)) 
            return true;
        
    }

    
    vis[row][col] = false;  // Unmark the cell if no valid path found
    return false;
}


bool ratInAMaze(int maze[][20], int n) {

    // Initialize the cell and vis arrays
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            cell[i][j] = maze[i][j];  // Assume maze[i][j] is 1 for open cell and 0 for blocked
            vis[i][j] = false;        // Initialize visited array to false
        }
    }

   
    return f(0, 0, n);   // Start solving the maze from the top-left corner

}
