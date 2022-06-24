#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printKnightsTour(vector<vector<int>>& chess, int n, int r, int c, int move) {
    if (r < 0 || r >= n || c < 0 || c >= 0 || chess[r][c] != 0)
        return;
    
    if (move == n * n) {
        chess[r][c] = n * n;
        display(chess);
        chess[r][c] = 0;
        return;
    }
  
  
  chess[r][c] = move;
  
  printKnightsTour(chess, n, r - 2, c + 1, move + 1);
  printKnightsTour(chess, n, r - 1, c + 2, move + 1);
  printKnightsTour(chess, n, r + 1, c + 2, move + 1);
  printKnightsTour(chess, n, r + 2, c + 1, move + 1);
  printKnightsTour(chess, n, r + 2, c - 1, move + 1);
  printKnightsTour(chess, n, r + 1, c - 2, move + 1);
  printKnightsTour(chess, n, r - 1, c - 2, move + 1);
  printKnightsTour(chess, n, r - 2, c - 1, move + 1);
  
  chess[r][c] = 0;
}