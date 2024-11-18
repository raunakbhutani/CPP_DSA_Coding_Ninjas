/*
Problem statement
You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.

A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
*/

#include <vector>
int n;
int cell[11][11];
vector<vector<int>> result;

bool isValid(int row, int col){  // to check whether we are placing queen at the correct loc or not

// cases: 
    
    // up
    for(int i = 0; i < row; i++){  // row no changes

        if(cell[i][col] == 1)
        return false;
    }

// top-left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {

        if (cell[i][j] == 1)
        return false;
    }

// top-right
    for(int i = row, j = col; i >=0 && j < n; i--, j++){

        if(cell[i][j] == 1)
        return false;
    }

    return true;
}

void print(){

    vector<int> solution;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            solution.push_back(cell[i][j]);
        }
    }
    
    result.push_back(solution);
}

void solve(int row){

    if(row == n){  // base case: i.e we have traversed all the cells
        print();
        return;
    }

    for(int j = 0; j < n; j++){

        if(isValid(row, j) == true){  // for this current col

            cell[row][j] = 1;   // place the queen

            solve(row + 1);  // now place queen on next row

            cell[row][j] = 0;   // during backtracking fill this cell with 0 to explore other solution
        }
    }
}


vector<vector<int>> solveNQueens(int m) {
    // Write your code here.
    result.clear();
     n = m;


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cell[i][j] = 0;
        }
    }


    solve(0);
    return result;
}
