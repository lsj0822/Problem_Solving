#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int>> Q;

int dx[2] = {0,1};
int dy[2] = {1,0};
int board[65][65], vst[65][65], n;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
    }
  }
  Q.push({0,0});
  vst[0][0] = 1;
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    if(board[cur.first][cur.second] == -1){
      cout << "HaruHaru";
      return 0;
    }
    for(int dir = 0; dir < 2; dir++){
      int nx = cur.first + dx[dir]*board[cur.first][cur.second];
      int ny = cur.second + dy[dir]*board[cur.first][cur.second];
      if(nx >= n || ny >= n) continue;
      if(vst[nx][ny]) continue;
      vst[nx][ny] = 1;
      Q.push({nx,ny});
    }
  }
  cout << "Hing";
  return 0;
}