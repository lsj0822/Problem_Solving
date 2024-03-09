#include <iostream>
#define DIV 1000000009
#define F first
#define S second
using namespace std;

int t;
pair<unsigned int, unsigned int> dp[100005];
int main(void)
{
  dp[1] = {1,0}; dp[2] = {1,1}; dp[3] = {2,2};
  for(int i = 4; i <= 100000; i++){
    dp[i] = {(dp[i-1].S + dp[i-2].S + dp[i-3].S)%DIV, (dp[i-1].F+dp[i-2].F+dp[i-3].F)%DIV};
  }
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << dp[n].first << ' ' << dp[n].second << '\n';
  } 
  return 0;
}