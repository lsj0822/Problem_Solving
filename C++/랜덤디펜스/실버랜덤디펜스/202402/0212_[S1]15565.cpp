#include <iostream>
#include <algorithm>
using namespace std;
int n, k, arr[1000005], idx = 0, ans = 1000005;

int main(void)
{
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    if(num == 1) arr[idx++] = i;
  }
  if(idx < k){
    cout << -1;
    return 0;
  }
  for(int i = k-1; i < idx; i++){
    ans = min(ans, arr[i] - arr[i-k+1] + 1);
  }
  cout << ans;
  return 0;
}