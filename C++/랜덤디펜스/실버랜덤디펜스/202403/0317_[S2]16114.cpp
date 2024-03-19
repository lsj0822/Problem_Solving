#include <iostream>
using namespace std;

int x, n;
int main(void)
{
  cin >> x >> n;
  if(n == 0){
    if(x > 0) cout << "INFINITE";
    else cout << 0;
    return 0;
  }
  else if(n == 1){
    if(x < 0) cout << "INFINITE";
    else cout << 0;
    return 0;
  }
  else if(n % 2 == 1){
    cout << "ERROR";
    return 0;
  }
  else{
    if(x <= 0) cout << 0;
    else{
      cout << (x+n/2-1)/(n/2) - 1;
    }
  }
  return 0;
}