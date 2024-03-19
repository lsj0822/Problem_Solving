#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int alpha[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int gunghap[4005][4005], ans = 0;
string a,b;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> a >> b;
  int n =a.length();
  for(int i = 0; i < n; i++){
    gunghap[0][2*i] = alpha[a[i] - 'A'];
    gunghap[0][2*i+1] = alpha[b[i] - 'A'];
  }
  for(int i = 1; i < 2*n - 1; i++){
    for(int j = 0; i + j < 2*n; j++){
      gunghap[i][j] = (gunghap[i-1][j] + gunghap[i-1][j+1])%10;
    }
  }
  ans = gunghap[2*n-2][0] * 10 + gunghap[2*n-2][1];
  cout << setfill('0') << setw(2) << ans;
  return 0;
}