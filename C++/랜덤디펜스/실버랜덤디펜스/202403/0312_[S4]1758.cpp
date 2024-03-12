#include <iostream>
#include <algorithm>
using namespace std;

long long n, ans = 0, arr[100005];
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(&arr[0], &arr[n], greater<long long>());
  for(int i = 0; i < n; i++) if(arr[i] - i > 0) ans += arr[i] - i;
  cout << ans;
  return 0;
}