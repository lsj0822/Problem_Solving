#include <iostream>
#include <string>
using namespace std;

string str;
int ans[2];
int main(void)
{
  cin >> str;
  int n = str.length();
  for(int i = 2; i < n; i++){
    if(str[i-1] == 'O' && str[i] == 'I'){
      if(str[i-2] == 'J') ans[0]++;
      if(str[i-2] == 'I') ans[1]++;
    }
  }
  for(auto r : ans){
    cout << r << '\n';
  }
  return 0;
}