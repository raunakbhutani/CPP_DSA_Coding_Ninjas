/*
Problem statement
You are given a 2D board('N' rows and 'M' columns) of characters and a string 'word'.

Your task is to return true if the given word exists in the grid, else return false. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
  */

#include <vector>
#include <iostream>

vector<vector<char>> board;
vector<vector<bool>> vis;

bool res = false;
int row, col;

string word;

bool isValid(int x, int y, char ch){
    
    if(x < 0 || x >= row || y < 0 || y >= col)  // out of cell
    return false;

    if(vis[x][y] == 1 || board[x][y] != ch)  // if alr visited that cell OR the char in cell is not equal to I/P char
    return false;

    return true;
}

bool dfs(int x, int y, int idx){

    vis[x][y] = true;

    if(idx == word.size() - 1){   // base case: i.e all char are matched

        return true;

    }

    if (isValid(x - 1, y, word[idx + 1])) { // up
        if (dfs(x - 1, y, idx + 1))
          return true;
    }

    if(isValid(x + 1, y, word[idx + 1])){   // down
    if(dfs(x + 1, y, idx +1))
    return true;
}

    if(isValid(x, y - 1, word[idx + 1])){   // left
    if(dfs(x, y - 1, idx + 1))
    return true;
}

    if(isValid(x, y + 1, word[idx + 1])){   // right
    if(dfs(x, y + 1, idx + 1))
    return true;
}

    vis[x][y] = false;   // unmark for further searches

    return false;    
}

bool present(vector<vector<char>> &b, string &w, int n, int m) 
{
   

    row = n;
    col = m;
    board = b;
    word = w;
    

    vis.assign(row, vector<bool>(col, false));  // 
    
    res = false;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(board[i][j] == word[0]){
                
                if(dfs(i, j, 0))
                return true;
            }
        }
    }

    return false;
}
