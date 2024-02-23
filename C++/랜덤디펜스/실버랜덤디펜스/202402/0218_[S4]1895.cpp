#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c, TV[45][45], T, ans = 0;
int main(void)
{
  cin >> r >> c;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> TV[i][j];
    }
  }
  cin >> T;
  
  for(int i = 0; i < r-2; i++){
    for(int j = 0; j < c-2; j++){
      vector<int> V;
      for(int k = 0; k < 9; k++){
        V.push_back(TV[i + k/3][j + k%3]);
      }
      sort(V.begin(), V.end());
      if(V[4] >= T) ans++;
    }
  }
  cout << ans;
  return 0;
}