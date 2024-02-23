#include <iostream>
using namespace std;

int n, a, d, ans = 0;
int main(void)
{
  cin >> n >> a >> d;
  for(int i = 0; i < n; i++){
    int k;
    cin >> k;
    if(k == a + ans*d) ans++;
  }
  cout << ans;
  return 0;
}