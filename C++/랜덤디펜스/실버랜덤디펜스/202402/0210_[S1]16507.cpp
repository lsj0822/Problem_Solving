#include <iostream>
using namespace std;

int r, c, q, photo[1005][1005], rsum[1005];
int main(void)
{
  cin >> r >> c >> q;
  for(int i = 1; i <= r; i++){
    int csum = 0;
    for(int j = 1; j <= c; j++){
      int k;
      cin >> k;
      csum += k;
      rsum[j] += csum;
      photo[i][j] = rsum[j];
    }
  }
  while(q--){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << (photo[r2][c2] - photo[r2][c1-1] - photo[r1-1][c2] + photo[r1-1][c1-1]) / ((r2-r1+1)*(c2-c1+1)) << '\n';
  }
  return 0;
}