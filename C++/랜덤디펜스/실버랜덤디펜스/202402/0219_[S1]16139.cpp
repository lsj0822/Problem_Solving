#include <iostream>
#include <string>
using namespace std;

int q, ans[200005][26], freq[26];
string str;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> str;
  for(int i = 1; i <= str.length(); i++){
    int f = str[i-1] - 'a';
    freq[f]++;
    for(int k = 0; k < 26; k++){
      ans[i][k] = freq[k];
    }
  }
  cin >> q;
  while(q--){
    char a;
    int b, c;
    cin >> a >> b >> c;
    cout << ans[c+1][a-'a'] - ans[b][a-'a'] << '\n';
  }
  return 0;
}