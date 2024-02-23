#include <iostream>
#include <string>

using namespace std;
string GCJ;
int n, ans[25];
bool fend = false;
void bt(int dep, int st){
  if(dep == n){
    if(st == 0 && !fend){
      for(int i = 0; i < n; i++){
        if(ans[i]) cout << '(';
        else cout << ')';
      }
      fend = true;
    }
    return;
  }
  if(GCJ[dep] == '('){
    ans[dep] = 1;
    bt(dep + 1, st + 1);
  }
  else if(GCJ[dep] == ')'){
    if(st){
      ans[dep] = 0;
      bt(dep + 1, st - 1);
    }
  }
  else{
    if(st){
      ans[dep] = 0;
      bt(dep + 1, st - 1);
    }
    ans[dep] = 1;
    bt(dep + 1, st + 1);
  }
}
int main(void)
{
  cin >> n >> GCJ;
  bt(0, 0);
  return 0;
}