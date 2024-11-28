/*
Problem statement
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
*/

#include <iostream>
#include <vector>
using namespace std;


bool isValid(int x, int y, int N, int M, bool** visited){

// the given cell(x, y) should be within the range 
    return(x >= 0 && x < N && y>=0 && y < M && !visited[x][y]);
}

bool searchWord(vector<vector<char>>& matrix, string target, int index, int x, int y, bool** visited){

    if(index == target.length())
    return true;  // found the entire word

    visited[x][y] = true;  // mark all the cells as visited(true)

// traverse all the 8 dir
    int dirX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dirY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for(int dir = 0; dir < 8; dir++){

        int newDirX = x + dirX[dir];
        int newDirY = y + dirY[dir];

        if(isValid(newDirX, newDirY, matrix.size(), matrix[0].size(), visited) && matrix[newDirX][newDirY] == target[index]){  // find a valid path

            if(searchWord(matrix, target, index + 1, newDirX, newDirY, visited))  // start from the next idx
            return true;
        }
    }

    visited[x][y] = false;  // backtrack & mark all the cells as unvisited(false) to discover other paths
    return false;
}

bool findPath(vector<vector<char>>& matrix, int N, int M){

    string target = "CODINGNINJA";

    bool** visited = new bool*[N];
    for(int i = 0; i < N; i++){

        visited[i] = new bool[M];
        for(int j = 0; j < M; j++){
            
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){

            if(matrix[i][j] == 'C'){  // start DFS if 'C' is found

                if(searchWord(matrix, target, 1, i, j, visited))
                return true;
            }
        }
    }

    return false;  // no path is found
}

int main()
{

    int N, M;
    cin >> N >> M;

    vector<vector<char>> matrix(N, vector<char>(M));  // NxM matrix for storing uppercase english letters

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){

            cin >> matrix[i][j];
        }
    }

    if(findPath(matrix, N, M))
    cout << 1;

    else
    cout << 0;
}
