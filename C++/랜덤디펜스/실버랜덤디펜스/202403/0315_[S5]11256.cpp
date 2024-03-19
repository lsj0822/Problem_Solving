#include <iostream>
#include <algorithm>
using namespace std;

int t;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while(t--){
    int j, n, arr[1005];
    cin >> j >> n;
    for(int i = 0; i < n; i++){
      int a,b;
      cin >> a >> b;
      arr[i] = a*b;
    }
    sort(&arr[0], &arr[n]);
    for(int b = 0; b < n; b++){
      j -= arr[n-1-b];
      if(j <= 0){
        cout << b+1 << '\n';
        break;
      }
    }
  }
  return 0;
}