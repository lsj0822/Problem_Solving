#include <iostream>
using namespace std;

int board[1025][1025], n, m, k;

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    int tsum = 0;
    for(int j = 1; j <= m; j++){
      int p;
      cin >> p;
      tsum += p;
      board[i][j] = tsum + board[i-1][j];
    }
  }
  cin >> k;
  for(int i = 0; i < k; i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << board[x2][y2] - board[x1-1][y2] - board[x2][y1-1] + board[x1-1][y1-1] << '\n';
  }
  return 0;
}