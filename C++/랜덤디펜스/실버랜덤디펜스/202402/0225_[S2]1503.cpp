#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[1001], ans = 1000000005;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int k;
    cin >> k;
    arr[k] = 1;
  }
  for(int i = 1; i <= 1000; i++){
    if(arr[i] == 1) continue;
    for(int j = i; j <= 1000; j++){
      if(arr[j] == 1) continue;
      for(int k = j; k <= 1001; k++){
        if(arr[k] == 1) continue;
        ans = min(ans, abs(n - i*j*k));
      }
    }
  }
  cout << ans;
}