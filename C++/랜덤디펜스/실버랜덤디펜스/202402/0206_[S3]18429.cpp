#include <iostream>
using namespace std;

int n,k, ex[10], vst[10], ans = 0;

void bt(int dep, int weight){
  if(dep == n){
    
    ans++;
    return;
  }
  for(int i = 0; i < n; i++){
    if(!vst[i] && weight + ex[i] - k * (dep + 1) >= 0){
      vst[i] = 1;
      bt(dep+1, weight + ex[i]);
      vst[i] = 0;
    }
  }
}
int main(void)
{
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> ex[i];
  }
  bt(0, 0);
  cout << ans;
  return 0;
}