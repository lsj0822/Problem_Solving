#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b, c, cal, cost, d[105], ans;

bool rs(int a, int b){
  return a > b;
}
int main(void)
{
  cin >> n >> a >> b >> c;
  cost = a; cal = c; ans = cal/cost;
  for(int i = 0; i < n; i++){
    cin >> d[i];
  }
  sort(&d[0], &d[n], rs);
  for(int i = 0; i < n; i++){
    cost += b; cal += d[i];
    ans = max(ans, cal/cost);
  }
  cout << ans;
  return 0;
}