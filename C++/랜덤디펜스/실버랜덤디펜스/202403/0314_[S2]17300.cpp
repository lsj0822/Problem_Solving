#include <iostream>
using namespace std;

int l, a[10], vst[3][3];
int main(void)
{
  cin >> l;
  for(int i = 0; i < l; i++){
    int k;
    cin >> k;
    a[i] = k-1;
  }
  vst[a[0]/3][a[0]%3] = 1;
  int ls = a[0];
  for(int i = 1; i < l; i++){
    if(vst[a[i]/3][a[i]%3] == 1){
      cout << "NO";
      return 0;
    }
    if((ls%3 != 1) && (a[i]%3 != 1)){
      if(a[i]/3 == ls/3){
        if(vst[a[i]/3][1] == 0){
          cout << "NO";
          return 0;
        }
      }
    }
    if((ls/3 != 1) && (a[i]/3 != 1)){
      if(a[i]%3 == ls%3){
        if(vst[1][a[i]%3] == 0){
          cout << "NO";
          return 0;
        }
      }
    }
    if((ls == 0 || ls == 8) && (a[i] == 0 || a[i] == 8)){
      if(vst[1][1] == 0){
        cout << "NO";
        return 0;
      }
    }
    if((ls == 2 || ls == 6) && (a[i] == 2 || a[i] == 6)){
      if(vst[1][1] == 0){
        cout << "NO";
        return 0;
      }
    }
    vst[a[i]/3][a[i]%3] = 1;
    ls = a[i];
  }
  cout << "YES";
  return 0;
}