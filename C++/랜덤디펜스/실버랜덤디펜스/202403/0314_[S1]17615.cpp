#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, freq = 0, ans = 500005;
char c[2] = {'B','R'};
string str;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> str;
  //case 1 : 왼쪽으로
  for(int col = 0; col < 2; col++){
    freq = 0;
    for(int i = str.find(c[col],0); i < n; i++){
      if(str[i] != c[col]) freq++;
    }
    ans = min(ans,freq);
  }
  //case 2 : 오른쪽으로, reverse 함수로 구함
  reverse(str.begin(), str.end());
  for(int col = 0; col < 2; col++){
    freq = 0;
    for(int i = str.find(c[col],0); i < n; i++){
      if(str[i] != c[col]) freq++;
    }
    ans = min(ans,freq);
  }
  cout << ans;
  return 0;
}