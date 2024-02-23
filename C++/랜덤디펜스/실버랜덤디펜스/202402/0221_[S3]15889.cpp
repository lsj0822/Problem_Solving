#include <iostream>
#include <queue>
using namespace std;

int n, pos[30005], pow[30005], vst[30005];
queue<int> Q;
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> pos[i];
  }
  for(int i = 0; i < n-1; i++){
    cin >> pow[i];
  }
  Q.push(0);
  vst[0] = 1;
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    if(cur == n-1){
      cout << "권병장님, 중대장님이 찾으십니다";
      return 0;
    }
    for(int i = cur+1; i < n; i++){
      if(pos[cur] + pow[cur] < pos[i]) break;
      if(vst[i]) continue;
      Q.push(i);
      vst[i] = 1;
    }
  }
  cout << "엄마 나 전역 늦어질 것 같아";
  return 0;
}