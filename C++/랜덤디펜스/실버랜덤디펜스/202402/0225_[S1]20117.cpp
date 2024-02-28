#include <iostream>
#include <algorithm>
using namespace std;

int n, price[100005], ans = 0;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> price[i];
  }
  sort(&price[0], &price[n]);
  for(int i = n / 2; i < n; i++){
    ans += 2 * price[i];
  }
  if(n%2) ans -= price[n/2];
  cout << ans;
  return 0;
}