#include <iostream>
#include <string>
using namespace std;

string str, x;
int b;
bool answer = false;
void check(int a){
  string new_str = to_string(a);
  int num = a, slen = str.length();
  while(1){
    if(slen == new_str.length()){
      if(num == stoi(str.substr(str.length()-to_string(num).length()))){
      answer = true;
      b = num;
      cout << a << " " << b << '\n';
      }
      return;
    }
    else if(slen < new_str.length()) return;
    num++;
    new_str += to_string(num);
  }
}
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> str;
  for(int i = 1; i <= 3; i++){
    x = str.substr(0,i);
    check(stoi(x));
    if(answer) return 0;
  }
}