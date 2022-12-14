#include<bits/stdc++.h>
using namespace std;

bool isQueenSafe(int row, int col, vector<vector<int>> chess) {
  for (int i = row - 1, j = col; i >= 0; i--) {
    if (chess[i][j] == 1) {
      return false;
    }
  }
  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if (chess[i][j] == 1) {
      return false;
    }
  }
  for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++) {
    if (chess[i][j] == 1) {
      return false;
    }
  }
  return true;
}


void printNQueens(vector<vector<int>> chess, string qsf, int row) {
  //base case
  if (row == chess.size()) {
    cout << qsf << ". " << endl;
    return;
  }
  //loop through columns
  for (int col = 0; col < chess.size(); col++) {
    if (isQueenSafe(row, col, chess)) {
      chess[row][col] = 1;
      printNQueens(chess, qsf + to_string(row) + "-" + to_string(col) + ", ", row + 1);
      chess[row][col] = 0;
    }
  }
}

int main() {
  int n;
  cout << "Enter size of board (N x N):";
  cin >> n;
  vector<vector<int>> chess(n, vector<int> (n));
  
  cout << endl;
  cout << "POSSIBLE PLACES OF QUEEN "<<endl;
  printNQueens(chess, "", 0);

}