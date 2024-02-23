#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int dist[205][205], n, x, y, gx, gy;
int dx[6] = {-2,-2,0,0,2,2};
int dy[6] = {-1,1,-2,2,-1,1};
queue<pair<int, int>> Q;
int main(void)
{
  fill(&dist[0][0], &dist[201][201], -1);
  cin >> n >> x >> y >> gx >> gy;
  dist[x][y] = 0;
  Q.push({x,y});
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    if(cur.X == gx && cur.Y == gy){
      cout << dist[cur.X][cur.Y];
      return 0;
    }
    for(int dir = 0; dir < 6; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n || dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx,ny});
    }
  }
  cout << -1;
  return 0;
}