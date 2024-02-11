#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 0, arr[100005];
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    int k;
    cin >> k;
    arr[i] = -k;
  }
  sort(&arr[0], &arr[n]);
  for(int i = 0; i < n; i++){
    if(i % 3 != 2) ans -= arr[i];
  }
  cout << ans;
  return 0;
}