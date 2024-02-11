#include <iostream>
using namespace std;

int n, ct[15], scale_pos[15], res[3000005], mx = 0, ans = 0;
void bt(int dep){
  if(dep == n){
    int tmp = 0;
    for(int i = 0; i < n; i++){
      tmp += scale_pos[i] * ct[i];
    }
    if(tmp > 0 && !res[tmp]) res[tmp] = 1;
    return;
  }
  for(int i : {-1,0,1}){
    scale_pos[dep] = i;
    bt(dep+1);
  }
}
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> ct[i];
    mx += ct[i];
  }
  bt(0);
  for(int i = 1; i <= mx; i++){
    ans += !(res[i]);
  }
  cout << ans;
  return 0;
}