#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, ans = 0;
int vst[1005];
string str;
queue<int> Q;
int main(void)
{
  cin >> n >> str;
  for(int i = 0; i < n; i++){
    if(!vst[i] && str[i] == 'E'){
      Q.push(i);
      vst[i];
      while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(str[cur] == 'E'){
          if(!vst[cur+1]){
            Q.push(cur+1);
            vst[cur+1] = 1;
          }
        }
        else{
          if(!vst[cur-1]){
            Q.push(cur-1);
            vst[cur-1] = 1;
          }
        }
      }
      ans++;
    }
  }
  cout << ans;
  return 0;
}