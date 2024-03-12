#include <iostream>
#include <string>
using namespace std;

string burger;
int n, k, board[10005], vst[10005], ans = 0;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k >> burger;
  for(int i = 0; i < n; i++){
    if(burger[i] == 'H'){
      for(int j = i-k; j <= i+k; j++){
        if(j < 0 || j >= n) continue;
        if(burger[j] == 'P' && vst[j] == 0){
          vst[j] = 1;
          ans++;
          break;
        }
      }
    }
  }
  cout << ans;
  return 0;
}