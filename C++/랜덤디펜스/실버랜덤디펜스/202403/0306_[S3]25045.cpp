#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long a[200005], b[200005], ans = 0;

bool rv(long long b1, long long b2){
  return b1 > b2;
}
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];
  sort(&a[0], &a[n], rv);
  sort(&b[0], &b[m]);
  for(int i = 0; i < min(n,m); i++){
    if(a[i] - b[i] < 0) continue;
    ans += a[i] - b[i];
  }
  cout << ans;
  return 0;
}