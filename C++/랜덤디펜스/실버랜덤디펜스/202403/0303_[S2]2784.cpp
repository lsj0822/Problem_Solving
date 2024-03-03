#include <bits/stdc++.h>
using namespace std;

string str[6];
int board[6], vst[6];
bool result = false;
void bt(int dep){
  bool ans = true;
  if(dep == 6){
    string vert[3];
    for(int i = 0; i < 3; i++) vert[i] = str[board[i]];
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
          if(str[board[i+3]][j] != vert[j][i]) ans = false;
      }
    }
    if(ans && !result){
      result = true;
      for(int i = 0; i < 3; i++){
        cout << vert[i] << '\n';
      }
    }
  }
  for(int i = 0; i < 6; i++){
    if(vst[i] == 1) continue;
    vst[i] = 1;
    board[dep] = i;
    bt(dep+1);
    vst[i] = 0;
  }
}
int main(void)
{
  for(int i = 0; i < 6; i++) cin >> str[i];
  bt(0);
  if(!result) cout << 0;
  return 0;
}