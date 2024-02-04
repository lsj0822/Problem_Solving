#include <iostream>
using namespace std;
int ls[10000005], n;
int main(void)
{
  cin >> n;
  for(int i = 1; i <= n; i++){
    int k = i, digit = 0;
    while(k!=0){
      digit += k%10;
      k /= 10;
    }
    if (!(i%digit)) ls[i] = ls[i-1] + 1;
    else ls[i] = ls[i-1];
  }
  cout << ls[n];
  return 0;
}