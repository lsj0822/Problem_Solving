#include <iostream>
#include <algorithm>
using namespace std;

int arr[2225], n, ans = 0;
int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(&arr[0], &arr[n]);
  for(int i = 0; i < n-1; i++){
    ans += arr[i];
  }
  cout << ans;
  return 0;
}