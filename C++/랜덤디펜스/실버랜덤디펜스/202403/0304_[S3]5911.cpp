#include <bits/stdc++.h>
using namespace std;

long long n, b, cost = 0, ans = 0, res;
pair<int, int> gift[1005];
bool giftsort(pair<int, int> a, pair<int, int> b) {
    return (a.first + a.second) < (b.first + b.second);
}
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> b;
    for (int i = 0; i < n; i++) cin >> gift[i].first >> gift[i].second;
    sort(&gift[0], &gift[n], giftsort);
    for (int i = 0; i < n; i++) {
      if(gift[i].first/2 + gift[i].second > b) continue;
        res = 1; cost = gift[i].first/2 + gift[i].second;
        for (int j = 0; j < n; j++) {
            if(j!=i){
              cost += gift[j].first + gift[j].second;
              if (cost > b) break;
              res++;
            }
        }
        ans = max(ans, res);
    }
    cout << ans;
}