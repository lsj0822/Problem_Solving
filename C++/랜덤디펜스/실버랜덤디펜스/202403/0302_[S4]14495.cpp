#include <iostream>
using namespace std;

long long fiboinga[117];
int main(void)
{
  fiboinga[1] = 1;
  fiboinga[2] = 1;
  fiboinga[3] = 1;
  for(int i = 4; i <= 116; i++){
    fiboinga[i] = fiboinga[i-1] + fiboinga[i-3];
  }
  int n;
  cin >> n;
  cout << fiboinga[n];
  return 0;
}