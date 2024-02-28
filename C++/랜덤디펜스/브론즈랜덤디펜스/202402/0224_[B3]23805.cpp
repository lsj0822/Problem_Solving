#include <iostream>
using namespace std;

int main(void)
{
  int n, board[501][501];
  cin >> n;
  for(int i = 0; i < 5*n; i++){
    for(int j = 0; j < n; j++){
      board[i][j] = 1;
      board[i][j+2*n] = 1;
      board[i][j+4*n] = 1;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      board[i][j+n] = 1;
      board[4*n+i][j+3*n] = 1;
    }
  }
  for(int i = 0; i < 5*n; i++){
    for(int j = 0; j < 5*n; j++){
      if(board[i][j]) cout << "@";
      else cout << " ";
    }
    cout << '\n';
  }
  return 0;
}