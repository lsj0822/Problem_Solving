#include <iostream>
#include <queue>
using namespace std;

int n, s, ai[100005], vst[100005], ans = 0;
queue<int> Q;
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> ai[i];
  }
  cin >> s;
  Q.push(s-1);
  vst[s-1] = 1;
  while(!Q.empty()){
    int cur = Q.front(); Q.pop();
    int d = ai[cur];
    for(int k : {cur - d, cur + d}){
      if(k >= n || k < 0) continue;
      if(vst[k]) continue;
      vst[k] = 1;
      Q.push(k);
    }
  }
  for(auto n : vst){
    ans += n;
  }
  cout << ans;
  return 0;
}