#include <iostream>
using namespace std;

int n, k, arr[1005], ans = 1005;
int main(void)
{
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  for(int i = 0; i < n; i++){
    int st = arr[i] - i * k, tmp = 0;
    if(st <= 0) continue;
    int cp = st;
    for(int j = 0; j < n; j++){
      if(cp != arr[j]) tmp++;
      cp+=k;
    }
    ans = min(ans, tmp);
  }
  cout << ans;
}