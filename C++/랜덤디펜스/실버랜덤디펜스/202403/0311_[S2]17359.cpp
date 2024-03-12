#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string bulb[11];
int n, vst[11], ls[11], ans = 100, changed = 0;

int cntbulb(){
  int res = 0;
  for(int i = 1; i < n; i++){
    if(bulb[ls[i]][0] != bulb[ls[i-1]][1]) res++;
  }
  return res;
}
void bt(int dep){
  if (dep == n){
    ans = min(ans, cntbulb());
    return;
  }
  for(int i = 0; i < n; i++){
    if(vst[i]) continue;
    vst[i] = 1;
    ls[dep] = i;
    bt(dep+1);
    vst[i] = 0;
  }
}
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;
    char c = str[0];
    for(int i = 1; i < str.length(); i++){
      if(c != str[i]){
        changed++;
        c = str[i];
      }
    }
    bulb[i] = str.substr(0,1) + str.substr(str.length() - 1, 1);
  }
  bt(0);
  cout << ans + changed;
  return 0;
}