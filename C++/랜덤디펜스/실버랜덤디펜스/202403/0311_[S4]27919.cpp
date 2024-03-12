#include <iostream>
#include <string>
using namespace std;

string str;
int cnt[2];
int main(void)
{
  cin >> str;
  if(str == ""){
    cout << "C";
    return 0;
  }
  for(auto i : str){
    if (i == 'U' || i == 'C') cnt[0]++;
    else cnt[1]++;
  }
  if(cnt[0] > (cnt[1]+1)/2) cout << 'U';
  if(cnt[1]) cout << "DP";
  return 0;
}