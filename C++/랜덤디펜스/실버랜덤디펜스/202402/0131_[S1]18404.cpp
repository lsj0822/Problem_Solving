#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int n,m, hx, hy, ex, ey;
int vst[505][505], result[1005];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> hx >> hy;
  fill(&vst[0][0], &vst[n][n], -1);
  queue<pair<int,int>> Q;
  Q.push({hx-1,hy-1});
  vst[hx-1][hy-1] = 0;
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 8; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if(vst[nx][ny] != -1) continue;
      vst[nx][ny] = vst[cur.X][cur.Y] + 1;
      Q.push({nx,ny});
    }
  }

  for(int r = 0; r < m; r++){
    cin >> ex >> ey;
    result[r] = vst[ex-1][ey-1];
  }
  for(int r = 0; r < m; r++){
    cout << result[r] << ' ';
  }
  return 0;
}