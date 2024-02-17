#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int t;
string str1, str2;
int main(void)
{
  cin >> t;
  while(t--){
    cin >> str1 >> str2;
    int diff[2] = {0} , slen = str1.length();
    for(int i = 0; i < slen; i++){
     if(str1[i] != str2[i]) diff[str1[i]-'0']++;
    }
    cout << max(diff[0],diff[1]) << '\n';
  }
  return 0;
}