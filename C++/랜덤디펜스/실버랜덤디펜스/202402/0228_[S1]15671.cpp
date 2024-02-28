#include <iostream>
using namespace std;

int board[7][7], ans[2];
int n;
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  fill(&board[0][0], &board[6][6]+1, -1);
  // 1 : white 0 : black
  board[3][3] = 1; board[4][4] = 1;
  board[3][4] = 0; board[4][3] = 0;
  cin >> n;
  for(int t = 0; t < n; t++){
    //even : black, odd : white
    bool turn = t%2;
    int x, y;
    cin >> x >> y;
    board[x][y] = turn;
    for(int dir = 0; dir < 8; dir++){
      int st = 1;
      bool flip = false;
      while(1){
        int nx = x + dx[dir]*st, ny = y + dy[dir]*st;
        if(nx < 0 || nx >= 7 || ny < 0 || ny >= 7) break;
        if(board[nx][ny] == -1) break;
        if(board[nx][ny] == turn) {
          flip = true;
          break;
        }
        st++;
      }
      if(flip){
        for(int i = 1; i < st; i++){
          int nx = x + dx[dir]*i, ny = y + dy[dir]*i;
          board[nx][ny] = turn;
        }
      }
    }
  }
  for(int i = 1; i <= 6; i++){
    for(int j = 1; j <= 6; j++){
      switch(board[i][j]){
        case 1:
        cout << 'W';
        ans[1]++;
        break;
        case 0:
        cout << 'B';
        ans[0]++;
        break;
        case -1:
        cout << '.';
        break;
      }
    }
    cout << '\n';
  }
  if(ans[0] > ans[1]) cout << "Black";
  else cout << "White";
  return 0;
}