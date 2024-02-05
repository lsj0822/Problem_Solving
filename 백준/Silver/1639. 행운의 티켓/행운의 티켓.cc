#include <iostream>
#include <string>
using namespace std;
string str;
int ans, ticket;
int make_sum(int st, int en){
  int res = 0;
  for(int i = st; i < en; i++){
    res += int(str[i] - '0');
  }
  return res;
}
int main(void)
{
  cin >> str;
  ticket = str.length();
  ans = ticket/2 * 2;
  while(ans){
    int mid = ans / 2;
    for(int i = 0; i <= ticket - ans; i++){
      if(make_sum(i,i+mid) == make_sum(i+mid, i+ans)){
        cout << ans;
        return 0;
      } 
    }
    ans -= 2;
  }
  cout << ans;
  return 0;
}