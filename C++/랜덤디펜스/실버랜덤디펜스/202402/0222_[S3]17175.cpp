#include <iostream>
using namespace std;

int f[55], n;
int main(void)
{
  f[0] = 1; f[1] = 1;
  for(int i = 2; i < 51; i++){
    f[i] = (1+f[i-1]+f[i-2])%1000000007;
  }
  cin >> n;
  cout << f[n];
}