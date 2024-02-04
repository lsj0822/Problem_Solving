#include <iostream>
using namespace std;

int k;
long long res[36];
int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> k;
  res[0] = 1;
  for(int i = 1; i <= k; i++){
    if(i%2){
      res[i] += res[i/2] * res[i/2];
    }
    for(int j = 0 ; j < i/2; j++){
    res[i] += 2 * res[j] * res[i-1-j];
    }
  }
  cout << res[k];
}