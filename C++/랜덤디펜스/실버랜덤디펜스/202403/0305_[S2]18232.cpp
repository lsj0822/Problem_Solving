#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int board[300005], s, e, n, m;
vector<vector<int>> teleport(300005);
queue<int> Q;
int main(void)
{
  ios::sync_with_stdio(0);cin.tie(0);
  cin >> n >> m >> s >> e;
  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    teleport[x].push_back(y);
    teleport[y].push_back(x);
  }
  fill(&board[0], &board[n+1], -1);
  board[s] = 0;
  Q.push(s);
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    //cout << cur << ' ';
    if(cur == e){
      cout << board[cur];
      return 0;
    }
    for(int i : {cur-1,cur+1}){
      if(i <= 0 || i > n || board[i] != -1) continue;
      board[i] = board[cur] + 1;
      Q.push(i);
    }
    for(int i : teleport[cur]){
      if(i <= 0 || i > n || board[i] != -1) continue;
      board[i] = board[cur] + 1;
      Q.push(i);
    }
  }
  return 0;
}