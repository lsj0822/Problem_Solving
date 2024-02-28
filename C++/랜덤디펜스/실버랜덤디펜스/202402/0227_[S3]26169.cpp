#include <iostream>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int board[5][5], vst[5][5], x, y;
bool ans = false;

void bt(int dep, int apple, int x, int y){
  if(apple >= 2) {
    ans = true;
    return;
  }
  if(dep == 3){
    return;
  }
  for(int dir = 0; dir < 4; dir++){
    int nx = x + dx[dir], ny = y + dy[dir];
    if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vst[nx][ny] == 1) continue;
    vst[nx][ny] = 1;
    if(board[nx][ny] == 1) bt(dep+1, apple+1, nx, ny);
    else bt(dep+1, apple, nx, ny);
    vst[nx][ny] = 0;
  }
}
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> board[i][j];
      if(board[i][j] == -1) vst[i][j] = 1;
    }
  }
  cin >> x >> y;
  vst[x][y] = 1;
  bt(0,0,x,y);
  cout << ans;
  return 0;
}