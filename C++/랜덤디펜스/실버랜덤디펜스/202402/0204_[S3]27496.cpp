#include <iostream>
using namespace std;

int n, l, c = 0, srt = 0, pend, ans = 0, a[1000005];

int main(void)
{
  cin >> n >> l;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < l; i++){
    c += a[i];
    if(c >= 129 && c <= 138) ans++;
  }
  
  pend = l;
  while(pend != n){
    c -= a[srt];
    c += a[pend];
    if(c >= 129 && c <= 138) ans++;
    srt++;
    pend++;
  }
  cout << ans;
  return 0;
}