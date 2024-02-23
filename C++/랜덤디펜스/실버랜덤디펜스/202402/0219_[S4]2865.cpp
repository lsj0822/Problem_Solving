#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, singer[105], ans = 0;

int main(void)
{
  cin >> n >> m >> k;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      int a;
      double b;
      cin >> a >> b;
      singer[a] = max(singer[a], int(b*10));
    }
  }
  sort(&singer[1], &singer[n+1]);
  for(int i = n; i > n-k; i--){
    ans += singer[i];
  }
  cout << double(ans)/10.;
  if(!(ans % 10)) cout << ".0";
  return 0;
}