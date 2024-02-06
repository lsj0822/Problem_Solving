#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

bool palin(string str){
  int slen = str.size(), smid = slen / 2;
  if(slen == 1) return true;
  string lstr, rstr;
  lstr = str.substr(0,smid);
  if(slen % 2) rstr = str.substr(smid+1);
  else rstr = str.substr(smid);

  if(lstr != rstr) return false;
  if(palin(lstr) && palin(rstr)) return true;
  return false;
}
int main(void)
{
  cin >> s;
  if(palin(s)) cout << "AKARAKA";
  else cout << "IPSELENTI";
  return 0;
}