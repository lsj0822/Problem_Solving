#include <iostream>
using namespace std;

int wj[9], sl[9], wscore = 0, sscore = 0;
bool ans = false;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i = 0; i < 9; i++) cin >> wj[i];
  for(int i = 0; i < 9; i++) cin >> sl[i];
  for(int i = 0; i < 9; i++){
    wscore += wj[i];
    if(wscore > sscore) ans = true;
    sscore += sl[i];
  }
  if(ans) cout << "Yes";
  else cout << "No";
  return 0;
}