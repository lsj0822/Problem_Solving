#include <bits/stdc++.h>
using namespace std;

int ans = 0, n, m, chicken[31][31], cselect[3];
void bt(int dep) {
    if (dep == 3) {
        int fav = 0;
        for (int j = 0; j < n; j++) {
            fav += max({ chicken[j][cselect[0]],chicken[j][cselect[1]],chicken[j][cselect[2]] });
        }
        ans = max(fav, ans);
        return;
    }
    for (int i = 0; i < m; i++) {
        cselect[dep] = i;
        bt(dep + 1);
    }
}
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> chicken[i][j];
        }
    }
    bt(0);
    cout << ans;
    return 0;
}