#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int n, ans[100005][2];
tuple<int,int,int> T[100005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    T[i] = make_tuple(a,b,c);
  }
  ans[0][0] = 0; ans[0][1] = get<2>(T[0]);
  ans[1][0] = ans[0][1]; ans[1][1] = get<2>(T[1]);
  for(int i = 2; i < n; i++){
    ans[i][0] = max(ans[i-1][0], ans[i-1][1]);
    ans[i][1] = max(ans[i-1][0], ans[i-2][1]) + get<2>(T[i]);
  }
  cout << max(ans[n-1][0], ans[n-1][1]);
  return 0;
}