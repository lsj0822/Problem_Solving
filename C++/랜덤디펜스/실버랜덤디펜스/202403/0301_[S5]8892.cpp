#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string words[105];
    int k;
    bool ans = false;
    cin >> k;
    for (int i = 0; i < k; i++) cin >> words[i];
      for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
          string combine;
          if(i == j) continue;
          combine += words[i] + words[j];
          string rcombine = combine;
          reverse(rcombine.begin(), rcombine.end());
          if (combine == rcombine) {
            cout << combine << '\n';
            ans = true;
            break;
          }
        }
        if (ans) break;
      }
      if (!ans) cout << 0 << '\n';
  }
  return 0;
}