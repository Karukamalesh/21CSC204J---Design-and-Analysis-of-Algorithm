#include <stdio.h>
#include <stdbool.h>

#define N 8  // Change N to solve for different sizes of the chessboard

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col) {
    // Check the column and diagonals for threats
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) 
            return false;
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1)
            return false;
        if (col + (row - i) < N && board[i][col + (row - i)] == 1)
            return false;
    }
    return true;
}

bool solveNQueens(int board[N][N], int row) {
    if (row >= N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1))
                return true;

            board[row][col] = 0;  // Backtrack
        }
    }
    return false;
}

int main() {
    int board[N][N] = {0};

    if (solveNQueens(board, 0)) {
        printSolution(board);
    } else {
        printf("Solution does not exist\n");
    }

    return 0;
}
