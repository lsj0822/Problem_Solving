#include <iostream>
#include <utility>
using namespace std;

int main(void)
{
  string s;
  cin >> s;
  char c[101];
  int l = s.length();
  for(int i = 0; i < l; i++){
    c[i] = s[i];
  }
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int a, b;
    cin >> a >> b;
    swap(s[a],s[b]);
  }
  for(int i = 0; i < l; i++){
    cout << s[i];
  }
}