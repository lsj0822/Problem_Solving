#include <iostream>
#include <string>
using namespace std;

string str;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> str;
  int slen = str.length();
  int ans = slen / 2 * 2;
  while(1){
    for(int i = 0; i <= slen - ans; i++){
      int lsum = 0, rsum = 0;
      for(int a = 0; a < ans/2; a++){
        lsum += str[i+a];
        rsum += str[ans/2+i+a];
      }
      if(lsum == rsum){
        cout << ans;
        return 0;
      }
    }
    ans -= 2;
  }
  return 0;
}