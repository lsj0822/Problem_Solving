#include <iostream>
using namespace std;

int n, trophy[55], lans = 1, rans = 1, lmax, rmax;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> trophy[i];
  }
  lmax = trophy[0]; rmax = trophy[n-1];
  for(int i = 1; i < n; i++){
    if(lmax < trophy[i]){
      lans++;
      lmax = trophy[i];
    }
    if(rmax < trophy[n-1-i]){
      rans++;
      rmax = trophy[n-1-i];
    }
  }
  cout << lans << '\n' << rans;
  return 0;
}