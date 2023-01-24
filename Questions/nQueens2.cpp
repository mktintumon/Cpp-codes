#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int chess[4][4], int N){
    for (int i = row - 1, j = col; i >= 0; i--) {
        if (chess[i][j] == 1) {
        return 0;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (chess[i][j] == 1) {
        return 0;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (chess[i][j] == 1) {
        return 0;
        }
    }

    return 1;
}

int n_queen(int row, int countQueen, int N, int board[4][4]){
    if (countQueen == 0) return 1;

    for (int j = 0; j < N; j++){
        if (isSafe(row, j, board, N)){
            board[row][j] = 1;

            if (n_queen(row + 1, countQueen - 1, N, board))
                return 1;

            board[row][j] = 0; //backtracking
        }
    }
    return 0;
}

int main(){
    int board[4][4];

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            board[i][j] = 0;
        }
    }

    n_queen(0, 4, 4, board);

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}