#include <iostream>
#include <queue>
using namespace std;

int n, m, t, ans = 0;
int board[1005][1005], vst[1005][1005];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
queue<pair<int,int>> Q;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int r, g, b;
      cin >> r >> g >> b;
      board[i][j] = (r+g+b)/3;
    }
  }
  cin >> t;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(board[i][j] >= t && vst[i][j] == 0){
        Q.push({i,j});
        vst[i][j] = 1;
        while(!Q.empty()){
          auto cur = Q.front(); Q.pop();
          for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vst[nx][ny] == 1 || board[nx][ny] < t) continue;
            Q.push({nx,ny});
            vst[nx][ny] = 1;
          }
        }
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}