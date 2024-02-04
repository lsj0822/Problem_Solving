#include <iostream>
using namespace std;

int n,p, ans = 0, num;
int modls[100];

int main(void)
{
  cin >> n >> p;
  num = n;
  while(true){
    num = (num*n)%p;
    if(modls[num] == 2) break;
    modls[num]++;
  }
  for(int i =0; i < p; i++){
    if(modls[i] == 2) ans++;
  }
  cout << ans;
  return 0;
}