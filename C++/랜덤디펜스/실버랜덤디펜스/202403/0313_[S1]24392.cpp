#include <iostream>
#define MOD 1000000007
using namespace std;

int n,m, board[1005][1005], dp[1005][1005], ans = 0;
int main(void)
{
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
    }
  }
  for(int i = 0; i < m; i++) dp[n-1][i] = board[n-1][i];
  for(int i = n-2; i >= 0; i--){
    for(int j = 0; j < m; j++){
      if(board[i][j] == 1){
        for(int k = j-1; k <= j+1; k++){
          if(k < 0 || k >= m) continue;
          dp[i][j] = (dp[i][j] + dp[i+1][k])%MOD;
        }
      }
    }
  }
  for(int i = 0; i < m; i++){
    ans = (ans + dp[0][i])%MOD;
  }
  cout << ans;
  return 0;
}