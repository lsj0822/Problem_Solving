#include <iostream>
#include <algorithm>
using namespace std;

int n,k,feed[25], dp[25];
int main(void)
{
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> feed[i];
  for(int i = 1; i <= n; i++){
    dp[i] = max(dp[i-1],dp[i]);
    int stat = 0, idx = i;
    stat += feed[i];
    while(1){
      if(stat >= k){
        dp[idx] = max(dp[i-1]+stat-k,dp[idx]);
        break;
      }
      if(idx == n) break;
      idx++;
      stat += feed[idx];
    }
  }
  cout << dp[n];
  return 0;
}