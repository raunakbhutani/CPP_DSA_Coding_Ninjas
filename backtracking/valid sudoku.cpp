/*
Problem statement
You have been given a 9 X 9 2D matrix 'MATRIX' with some cells filled with digits(1 - 9), and some empty cells (denoted by 0).

You need to find whether there exists a way to fill all the empty cells with some digit(1 - 9) such that the final matrix is a valid Sudoku solution.

A Sudoku solution must satisfy all the following conditions-

1. Each of the digits 1 - 9 must occur exactly once in each row.
2. Each of the digits 1 - 9 must occur exactly once in each column.
3. Each of the digits 1 - 9 must occur exactly once in each of the 9, 3 x 3 sub-matrices of the matrix.
Note
1. There will always be a cell in the matrix which is empty.
2. The given initial matrix will always be consistent according to the rules mentioned in the problem statement.
*/

bool isValid(int matrix[9][9], int row, int col, int num){

  for (int i = 0; i < 9; i++) {  // check if num isn't repeated in the row

    if (matrix[row][i] == num) // if num is repeated
      return false;
  }
  for (int i = 0; i < 9; i++) {  // check if num isn't repeated in the col
   
    if (matrix[i][col] == num)  // if num is repeated
      return false;
    }
    
// calc the starting row & col for 3x3 subgrid    
    int startRow = row - row % 3;
    int startCol = col - col % 3;

// check if num is repeated in the 3x3 subgrid
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            if(matrix[i + startRow][j + startCol] == num)
            return false;
        }
    }

    return true;  // if num isn't repeated in all of the above 3 cases

    }

bool solve(int matrix[9][9]){

    int row = -1, col = -1;
    bool isEmpty = false;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){

            if(matrix[i][j] == 0){  // if the cell is empty (denoted by 0)

                row = i;  // store the val of row
                col = j;  // store the value of col
                isEmpty = true;   // make isEmpty true
                break;
            }
        }
        if(isEmpty == true)
        break;
    }

     if(!isEmpty)  // bvase case: no empty cell left, puzzle solved
     return true;

// try placing digits from 1 to 9 in empty cell
     for(int num = 1; num <= 9; num++){

         if(isValid(matrix, row, col, num)){  // check is it valid to place num in empty cell

            matrix[row][col] = num;

            if(solve(matrix) == true)  // if that leads to the sol
            return true;

            matrix[row][col] = 0;  // backtrack, if placing num wasn't correct in empty cell
         }
     }

     return false;  // if no num b/w 1-9 works
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.

    return solve(matrix);
    
}
