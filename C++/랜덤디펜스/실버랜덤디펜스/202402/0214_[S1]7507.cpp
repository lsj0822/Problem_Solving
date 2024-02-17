#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

bool sportsort(tuple<int, int, int> a, tuple<int, int, int> b){
  if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
  else if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
  else return get<1>(a) < get<1>(b);
}
int n, m, d, s, e;
int main(void)
{
  cin >> n;
  for(int t = 1; t <= n; t++){
    int ans = 1, day, en;
    cin >> m;
    tuple<int, int, int> sport[50005];
    for(int i = 0; i < m; i++){
      cin >> d >> s >> e;
      sport[i] = make_tuple(d,s,e);
    }
    sort(&sport[0], &sport[m], sportsort);
    day = get<0>(sport[0]); en = get<2>(sport[0]);
    for(int i = 1; i < m; i++){
      auto cur = sport[i];
      if(day != get<0>(cur)){
        ans++; 
        day = get<0>(cur); 
        en = get<2>(cur);
      }
      else{
        if(en <= get<1>(cur)){
          ans++; 
          en = get<2>(cur);
        }
      }
    }
    cout << "Scenario #" << t << ":\n" << ans << "\n\n";
  }
  return 0;
}