#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long candy[300005], c = 0;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    long long k;
    cin >> k;
    c += k;
    candy[i] = c;
  }
  for(int i = 0; i < n; i++){
    long long k;
    cin >> k;
    if(k > candy[m]) {
      cout << "Go away!" << '\n';
      continue;
    }
    int ans = lower_bound(&candy[0], &candy[m], k) - &candy[0];
    cout << ans << '\n';
  }
  return 0;
}