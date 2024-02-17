#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n, MXidx;
long long lroad[100005], rroad[100005], cross[100005], ltotal = 0, rtotal = 0, ans = 10e+18;
stack<int> S;
int main(void)
{
  ios::sync_with_stdio(0); 
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> cross[i];
  }
  for(int i = 1; i < n; i++){
    int k;
    cin >> k;
    ltotal += k;
    lroad[i] = ltotal;
  }
  for(int i = 1; i < n; i++){
    int k;
    cin >> k;
    S.push(k);
  }
  for(int i = 1; i < n; i++){
    rtotal += S.top();
    S.pop();
    rroad[n-1-i] = rtotal;
  }
  for(int i = 0; i < n; i++){
    if(ans > cross[i] + lroad[i] + rroad[i]){
      ans = cross[i] + lroad[i] + rroad[i];
      MXidx = i+1;
    }
  }
  cout << MXidx << " " << ans;
  return 0;
}