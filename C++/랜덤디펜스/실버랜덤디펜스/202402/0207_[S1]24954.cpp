#include <iostream>
#include <algorithm>
using namespace std;

int n, potion[12], vst[12], sale[12][12], ans = 10000000, a, d, p;
void bt(int dep, int cost){
  if(dep == n){
    ans = min(ans, cost);
    return;
  }
  for(int i = 0; i < n; i++){
    if(!vst[i]){
      for(int k = 0; k < n; k++) {
        potion[k] -= sale[i][k];
      }
      vst[i] = dep+1;
      if(potion[i] > 0){
        bt(dep+1,cost+potion[i]);
      } 
      else {
        bt(dep+1,cost+1);
      }
      vst[i] = 0;
      for(int k = 0; k < n; k++) {
        potion[k] += sale[i][k];
      }
    }
  }
}
int main(void)
{
  cin >> n;
  fill(&sale[0][0], &sale[n][n], 0);
  for(int i = 0; i < n; i++) cin >> potion[i];
  for(int i = 0; i < n; i++){
    cin >> p;
    for(int j = 0; j < p; j++){
      cin >> a >> d;
      sale[i][a-1] = d;
    }
  }
  bt(0, 0);
  cout << ans;
  return 0;
}