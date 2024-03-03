#include <iostream>
#include <algorithm>
using namespace std;

long long a[500005], b[500005];
int n;
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n-1; i++) cout << lower_bound(&b[i+1], &b[n], a[i]+1) - &b[i+1] << ' ';
  cout << 0;
  return 0;
}