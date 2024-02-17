#include <iostream>
#include <string>
using namespace std;

string num;
int ans = 1, idx = 0;
int main(void)
{
  cin >> num;
  int numlen = num.length();
  while(idx < numlen){
      string tmp = to_string(ans);
      for(int i = 0; i < tmp.length(); i++){
        if(tmp[i] == num[idx]) idx++;
      }
      ans++;
  }
  cout << ans - 1;
  return 0;
}