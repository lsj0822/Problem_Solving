#include <iostream>
using namespace std;

int t, n, ans[1005];
int main(void)
{
  ans[1] = 1; ans[2] = 2; ans[3] = 2;
  for(int i = 4; i <= 1000; i++){
    if(i%2) ans[i] += 1;
    else ans[i] += ans[i/2]+1;
    int mid = (i - 1) / 2;
    for(int k = 1; k <= mid; k++){
      ans[i] += ans[k];
    }
  }
  cin >> t;
  while(t--){
    cin >> n;
    cout << ans[n] << '\n';
  }
  return 0;
}