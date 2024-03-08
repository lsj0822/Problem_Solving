#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 0, dp[300005];
vector<int> td;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i < 125; i++) {
    int val = i * (i + 1) * (i + 2) / 6;
    if(val > 300000) break;
    td.push_back(val);
  }
  fill(&dp[1], &dp[n+1], 500);

  for(int i = 1; i <= n; i++){
    for(int j = 0; j < td.size(); j++){
      if(i - td[j] < 0) break;
      dp[i] = min(dp[i], dp[i-td[j]]+1);
    }
  }
  cout << dp[n];
}