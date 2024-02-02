#include <iostream>
#include <string>
#include <queue>
#define X first
#define Y second
using namespace std;
//x좌표와 y좌표가 달라 헷갈리는 문제. 아예 처음부터 y좌표를 먼저 받았다.
int n, m, bp = 0, wp = 0;
string str[105];
bool vst[105][105];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int bfs(int x, int y, char c){
  queue<pair<int ,int>> Q;
  Q.push({x,y});
  vst[x][y] = 1;
  int res = 1;
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(str[nx][ny] != c || vst[nx][ny]) continue;
      vst[nx][ny] = 1;
      Q.push({nx,ny});
      res++;
    }
  }
  return res;
}
int main(void)
{
  cin >> m >> n;
  for(int i = 0; i < n; i++){
    cin >> str[i];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!vst[i][j]){
        char c = str[i][j];
        int res = bfs(i,j,c);
        if(c == 'W') wp += res*res;
        else bp += res*res;
      }
    }
  }
  cout << wp << " " << bp;
  return 0;
}