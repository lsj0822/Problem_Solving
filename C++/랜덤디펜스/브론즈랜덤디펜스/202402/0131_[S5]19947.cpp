#include <iostream>
#include <algorithm>
using namespace std;
int m, y;
int c[100005];
int main(void)
{
  cin >> m >> y;
  fill(&c[0],&c[y],0);
  c[y] = m;
 for(int i = y; i >= 0; i--){
    if(i >= 1) c[i-1] = max(c[i-1],(int)(c[i]*1.05));
    if(i >= 3) c[i-3] = max(c[i-3],(int)(c[i]*1.2));
    if(i >= 5) c[i-5] = max(c[i-5],(int)(c[i]*1.35));
  }
  cout << c[0];
  return 0;
  
}