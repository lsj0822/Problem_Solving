#include <iostream>
#include <string>

using namespace std;

int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

string mine[1005];
int n;


int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> mine[i];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(mine[i][j] != '.'){
        cout << '*';
        continue;
      }
      int total = 0;
      for(int dir = 0; dir < 8; dir++){
        int nx = i + dx[dir], ny = j + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(mine[nx][ny] != '.') total += mine[nx][ny] - '0';
      }
      if(total >= 10) cout << 'M';
      else cout << total;
    }
    cout << '\n';
  }
  return 0;
}