#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int board[1005][1005], dist[1005][1005];
int x, y, n;
queue<pair<int,int>> Q;
int main(void)
{
  fill(&dist[0][0], &dist[1002][0], -1);
  cin >> x >> y >> n;
  x += 500;
  y += 500;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    board[a+500][b+500] = 1;
  }
  Q.push({500,500});
  dist[500][500] = 0;
  while(1){
    auto cur = Q.front(); Q.pop();
    if(cur.first == x && cur.second == y){
      cout << dist[x][y];
      return 0;
    }
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
      if(nx < 0 || nx > 1000 || ny < 0 || ny > 1000) continue;
      if(board[nx][ny] == 1 || dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[cur.first][cur.second] + 1;
      Q.push({nx,ny});
    }
  }
  return 0;
}