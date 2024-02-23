#include <iostream>
#include <queue>
using namespace std;

int n, k, ls[100005], vst[100005];
queue<int> Q;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> ls[i];
  }
  Q.push(0);
  vst[0] = 1;
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int i = cur+1; i < n; i++){
      if((i-cur)*(1 + abs(ls[i]-ls[cur])) <= k){
        if(i == n-1){
          cout << "YES";
          return 0;
        }
        if(!vst[i]){
          vst[i] = 1;
          Q.push(i);
        }
      }
    }
  }
  cout << "NO";
  return 0;
}