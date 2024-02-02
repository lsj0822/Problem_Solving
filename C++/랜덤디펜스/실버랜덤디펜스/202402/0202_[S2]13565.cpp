#include <iostream>
#include <string>
#include <queue>
#define X first
#define Y second
using namespace std;

int n, m;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
string str[1005];
bool vst[1005][1005];
queue<pair<int, int>> Q;
int main(void)
{
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> str[i];
  }
  for(int i = 0; i < m; i++){
    if(str[0][i] == '0'){
      Q.push({0,i});
      vst[0][i] = 1;
    }
  }
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx == n - 1){
        cout << "YES";
        return 0;
      }
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(vst[nx][ny] || str[nx][ny] == '1') continue;
      Q.push({nx,ny});
      vst[nx][ny] = 1;
    }
  }
  cout << "NO";
  return 0;
}