#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  while(1){
    long long arr[250001], dp[250001];
    cin >> n;
    ans = -10001;
    if(n == 0) return 0;
    for(int i = 0; i < n; i++) cin >> arr[i];
    dp[0] = arr[0];
    for(int i = 1; i < n; i++){
      dp[i] = max(dp[i-1]+arr[i],arr[i]);
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
}