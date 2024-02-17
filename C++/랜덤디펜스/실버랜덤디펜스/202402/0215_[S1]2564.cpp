#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int x, y, n, ans = 0, ddir, ddist, peri,shop[105];

int distance(int dir, int length){
  switch(dir){
      case 1:
      return length;
      break;
      case 2:
      return (2*x + y - length);
      break;
      case 3:
      return (peri - length);
      break;
      case 4:
      return (x + length);
      break;
  }
}
int main(void)
{
  cin >> x >> y >> n;
  peri = (x + y) * 2;
  for(int i = 0; i < n; i++){
    int dir, dist;
    cin >> dir >> dist;
    shop[i] = {distance(dir,dist)};
  }
  cin >> ddir >> ddist;
  int dong = distance(ddir, ddist);
  for(int i = 0; i < n; i++){
    int cur = shop[i];
    ans += min(abs(cur - dong),peri-abs(cur - dong));
    }
  cout << ans;
  return 0;
}