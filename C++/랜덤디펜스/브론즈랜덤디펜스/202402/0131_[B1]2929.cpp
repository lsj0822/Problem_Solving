#include <iostream>
#include <string>
using namespace std;
int ans = -3, chk = 0;
int main(void)
{
  string str;
  cin >> str;
  for(char c : str){
    if(c >= 'A' && c <= 'Z'){
      ans += (3-(chk)%4);
      chk = 0;
    }
    else{
      chk++;
    }
  }
  cout << ans;
  return 0;
}