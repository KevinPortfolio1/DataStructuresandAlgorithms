//1. 八后問題

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<int>& queens, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<int>& queens, int row, vector<vector<int>>& solutions) {
    if (row == 8) {
        solutions.push_back(queens);
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solveNQueens(queens, row + 1, solutions);
        }
    }
}

int main() {
    vector<int> queens(8);
    vector<vector<int>> solutions;
    solveNQueens(queens, 0, solutions);

    for (const auto& solution : solutions) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << (solution[i] == j ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

//2. 迷宫問題

#include <iostream>
#include <vector>

using namespace std;

const int N = 5;
int maze[N][N] = {
    { 1, 0, 0, 0, 0 },
    { 1, 1, 0, 1, 1 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 1 },
    { 0, 0, 0, 0, 1 }
};

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(int x, int y, vector<vector<int>>& solution) {
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(x, y)) {
        solution[x][y] = 1;

        if (solveMazeUtil(x + 1, y, solution)) return true;
        if (solveMazeUtil(x, y + 1, solution)) return true;

        solution[x][y] = 0; // backtrack
    }
    return false;
}

void solveMaze() {
    vector<vector<int>> solution(N, vector<int>(N, 0));
    if (!solveMazeUtil(0, 0, solution)) {
        cout << "No solution exists";
        return;
    }

    for (const auto& row : solution) {
        for (int cell : row) {
            cout << (cell ? "1 " : "0 ");
        }
        cout << endl;
    }
}

int main() {
    solveMaze();
    return 0;
}

//3. 騎士路徑問題

#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

int moveX[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int moveY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool isSafe(int x, int y, const vector<vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

bool solveKnightTourUtil(int x, int y, int movei, vector<vector<int>>& board) {
    if (movei == N * N) {
        return true;
    }

    for (int k = 0; k < 8; k++) {
        int next_x = x + moveX[k];
        int next_y = y + moveY[k];
        if (isSafe(next_x, next_y, board)) {
            board[next_x][next_y] = movei;
            if (solveKnightTourUtil(next_x, next_y, movei + 1, board)) {
                return true;
            }
            board[next_x][next_y] = -1; // backtrack
        }
    }
    return false;
}

void solveKnightTour() {
    vector<vector<int>> board(N, vector<int>(N, -1));
    board[0][0] = 0; // starting position

    if (!solveKnightTourUtil(0, 0, 1, board)) {
        cout << "No solution exists";
        return;
    }

    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }
}

int main() {
    solveKnightTour();
    return 0;
}