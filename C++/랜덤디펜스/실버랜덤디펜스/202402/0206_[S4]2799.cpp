#include <iostream>
using namespace std;

int m, n, ans[5];
string str[600];
int main(void)
{
  cin >> m >> n;
  for(int i = 0; i < 5*m + 1; i++){
    cin >> str[i];
  }
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      for(int r = 0; r < 5; r++){
        if(str[5*i+1+r][5*j+1] == '.') {
          ans[r]++;
          break;
        }
        if(r == 4) ans[4]++;
      }
    }
  }

  for(int i = 0; i < 5; i++){
    cout << ans[i] << " ";
  }
  return 0;
}