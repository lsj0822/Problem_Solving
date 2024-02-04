#include <iostream>
#include <string>
using namespace std;

string str;

int main(void)
{
  int ans = 0;
  cin >> str;
  for(auto c : str){
    if(c == '@') ans++;
    if(c == '0') {
      cout << ans << " ";
      ans = 0;
    }
  }
  cout << ans;
  return 0;
}