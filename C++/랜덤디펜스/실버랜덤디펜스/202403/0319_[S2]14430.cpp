#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int board[305][305], dp[305][305];
int dx[2] = {0,1};
int dy[2] = {1,0};
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
    }
  }
  dp[0][0] = board[0][0];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      for(int dir = 0; dir < 2; dir++){
        int nx = i - dx[dir], ny = j - dy[dir];
        if(nx < 0 || ny < 0) continue;
        dp[i][j] = max(dp[i][j],dp[nx][ny] + board[i][j]);
      }
    }
  }
  cout << dp[n-1][m-1];
  return 0;
}