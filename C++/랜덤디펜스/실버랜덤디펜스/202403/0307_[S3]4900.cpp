#include <iostream>
#include <string>
using namespace std;

string seg[10] = {"063","010","093","079","106","103","119","011","127","107"};
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  while(1){
    string str, num1, num2;
    cin >> str;
    if(str == "BYE") return 0;
    int a = str.find('+'), b = str.find('=');
    for(int i = 0; i < a; i+=3){
      for(int n = 0; n < 10; n++){
        if(seg[n] == str.substr(i,3)){
          num1 += '0' + n;
          break;
        }
      }
    }
    for(int i = a+1; i < b; i+=3){
      for(int n = 0; n < 10; n++){
        if(seg[n] == str.substr(i,3)){
          num2 += '0' + n;
          break;
        }
      }
    }
    int ans = stoi(num1) + stoi(num2);
    cout << str;
    string sans = to_string(ans);
    for(auto c : sans){
      cout << seg[c-'0'];
    }
    cout << '\n';
  }
  return 0;
}