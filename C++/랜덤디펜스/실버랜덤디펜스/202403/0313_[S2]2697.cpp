#include <bits/stdc++.h>
using namespace std;
int t;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while(t--){
    string str;
    cin >> str;
    if(next_permutation(str.begin(), str.end())){
      for(char c : str) cout << c;
    }
    else cout << "BIGGEST";
    cout << '\n';
  }
}