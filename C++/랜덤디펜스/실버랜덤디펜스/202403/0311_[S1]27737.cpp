#include <iostream>
#include <queue>
using namespace std;
int board[105][105], vst[105][105];
int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
int n, m, k, ans = 0;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(!board[i][j] && !vst[i][j]){
        int cnt = 1;
        queue<pair<int,int>> Q;
        Q.push({i,j});
        vst[i][j] = 1;
        while(!Q.empty()){
          auto cur = Q.front(); Q.pop();
          for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] || vst[nx][ny]) continue;
            cnt++;
            vst[nx][ny] = 1;
            Q.push({nx,ny});
          }
        }
        ans += (cnt-1)/k + 1;
      }
    }
  }
  if(ans == 0){
    cout << "IMPOSSIBLE";
    return 0;
  }
  if(ans <= m) cout << "POSSIBLE\n" << m - ans;
  else cout << "IMPOSSIBLE";
  return 0;
}