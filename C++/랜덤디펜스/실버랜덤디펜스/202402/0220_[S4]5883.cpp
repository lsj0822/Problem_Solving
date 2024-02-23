#include <iostream>
using namespace std;

int n, arr[1005], rm = 0, ans = 1;
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  for(int i = 0; i < n; i++){
   int rm = arr[i], pv = arr[0], llen = 1, tmp = -1; //rm 지울숫자 pv 이전숫자
    for(int j = 1; j < n; j++){
      if(pv != arr[j] && rm != arr[j]){
        pv = arr[j];
        tmp = max(llen, tmp);
        llen = 1;
      }
      else if(pv == arr[j]){
        llen++;
      }
    }
    tmp = max(llen, tmp);
    ans = max(ans, tmp);
  }
  cout << ans;
  return 0;
}