#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n;
vector<string> num;

bool compare(string a, string b){
  if(a.length() != b.length()) return a.length() < b.length();
  else{
    for(int i = 0; i < a.length(); i++){
      if(a[i] != b[i]) return a[i] < b[i];
    }
  }
}
int main(void)
{
  cin >> n;
  while(n--){
    string str;
    cin >> str;
    int nlen = 1, st;
    bool isnum = false, iszero = false;
    for(int i = 0; i < str.length(); i++){
      if(str[i] >= '1' && str[i] <= '9' && !isnum){
        isnum = true;
        iszero = false;
        st = i;
      }
      if(str[i] == '0' && !isnum) iszero = true;
      if(str[i] >= 'a' && iszero){
        num.push_back("0");
        iszero = false;
      }
      if(str[i] >= 'a' && isnum){
        num.push_back(str.substr(st,nlen-1));
        nlen = 1;
        isnum = false;
      }
      if(isnum) nlen++;
    }
    if(isnum) num.push_back(str.substr(st,str.length()));
    if(iszero) num.push_back("0");
  }
  sort(num.begin(),num.end(),compare);
  for(auto c : num){
    cout << c << '\n';
  }
  return 0;
}