#include <iostream>

using namespace std;
int n, arr[300005], ans = 0;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  int ans = n;
  for(int i = n-1; i >= 0; i--){
    if(arr[i] == ans) ans--;
  }
  cout << ans;
  return 0;
}