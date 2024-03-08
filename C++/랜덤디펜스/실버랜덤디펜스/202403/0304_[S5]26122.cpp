#include <iostream>
using namespace std;

int k, ans = 0, str[300005];
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> k;
  for(int i = 0; i < k; i++){
    char c;
    cin >> c;
    if(c == 'N') str[i] = 1;
    else str[i] = 0;
  }
  int bf = str[0], bfcnt = 0, cnt = 1;
  for(int i = 1; i < k; i++){
    if(bf != str[i]){
      ans = max(ans, min(bfcnt,cnt));
      bfcnt = cnt;
      cnt = 1;
      bf = str[i];
    }
    else cnt++;
  }
  ans = max(ans, min(bfcnt,cnt));
  cout << ans*2;
  return 0;
}