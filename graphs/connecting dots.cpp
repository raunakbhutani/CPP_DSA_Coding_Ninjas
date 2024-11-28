/*
Problem statement
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
  */

#include <iostream>
using namespace std;

bool isValid(int x, int y, int N, int M, char** board, bool** visited, char color){  // N rows M cols
    // func to check whether the cell is within the dimnesions of board

    return(x >= 0 && x < N && y >= 0 && y < M && board[x][y] == color && !visited[x][y]);
}

bool DFS(char** board, bool** visited, int x, int y, int parentX, int parentY, int N, int M, char color, int count){

    visited[x][y] = true;  // mark the current cell as visited

// left(x - 1, y)
    if(isValid(x - 1, y, N, M, board, visited, color)){

        if(DFS(board, visited, x -1 , y, x, y, N, M, color, count + 1))
        return true;
    }

    else if (visited[x - 1][y] && (x - 1 != parentX && y != parentY) && count >= 4)
    return true;

// down(x + 1, y) 
    if(isValid(x + 1, y, N, M board, visited, color)){

        if(DFS(board, visited, x + 1 , y, x, y, N, M, color, count + 1))
        return true;
    }

    else if (visited[x + 1][y] && (x + 1 != parentX && y != parentY) && count >= 4)
    return true;
    
// left(x, y - 1)
    if(isValid(x, y - 1, N, M board, visited, color)){

        if(DFS(board, visited, x , y - 1, x, y, N, M, color, count + 1))
        return true;
    }

    else if (visited[x][y - 1] && (x != parentX && y - 1 != parentY) && count >= 4)
    return true;

// right(x, y + 1)    
    if(isValid(x, y + 1, N, M board, visited, color)){

        if(DFS(board, visited, x , y + 1, x, y, N, M, color, count + 1))
        return true;
    }

    else if (visited[x][y + 1] && (x != parentX && y + 1 != parentY) && count >= 4)
    return true;

    visited[x][y] = false;  // bavktrack & mark all cells as unvisited(false) to explore other paths
    return false;

}


bool containsCycle(char** board, int N, int M){

    bool** visited = new bool*[N];
    for(int i = 0; i < N; i++){

        visited[i] = new bool[M];
        for(int j = 0; j < M; j++){

            visited[i][j] = false;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){

            if(!visited[i][j]){
                if(DFS(board, visited, i, j, -1, -1, N, M, board[i][j], 1)){

                    for(int k = 0; k < N; k++){

                        delete [] visited[k];
                    }
                    delete [] visited;
                    return true ;
                }
            }
        }
    }

    for(int i = 0; i < N; i++){

        delete [] visited[i];
    }
    delete [] visited;

    return false;
}

int main()
{
    //Write your code here

    int N, M;
    cin >> N >> M;

    char** board = new char*[N];
    for(int i = 0; i < N; i++){

        board[i] = new char[M];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){

            cin >> board[i][j];
        }
    }

    if(containsCycle(board, N, M))
    cout << "true";

    else
    cout << "false";

    for(int i = 0; i < N; i++){

        delete [] board[i];
    }
    delete [] board;
}
