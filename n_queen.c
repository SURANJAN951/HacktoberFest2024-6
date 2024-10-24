#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int board[MAX][MAX];

// Function to print the solution
void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(int row, int col, int n) {
    int i, j;

    // Check the same column
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Function to solve the N-Queen problem using backtracking
bool solveNQueen(int row, int n) {
    // Base case: If all queens are placed
    if (row == n) {
        printSolution(n);
        return true;
    }

    bool res = false;

    // Consider this row and try placing queens in all columns one by one
    for (int i = 0; i < n; i++) {
        if (isSafe(row, i, n)) {
            // Place the queen
            board[row][i] = 1;

            // Recur to place the rest of the queens
            res = solveNQueen(row + 1, n) || res;

            // If placing queen at board[row][i] doesn't lead to a solution, remove the queen
            board[row][i] = 0; // Backtrack
        }
    }

    return res;
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n >= MAX) {
        printf("Please enter N less than %d\n", MAX);
        return 1;
    }

    // Initialize the board with 0s
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    if (!solveNQueen(0, n)) {
        printf("Solution does not exist.\n");
    }

    return 0;
}
