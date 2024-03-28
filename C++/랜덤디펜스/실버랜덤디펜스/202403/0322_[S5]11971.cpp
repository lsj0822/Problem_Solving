#include <iostream>
using namespace std;

int lim[101], speed[101], ans = 0, n, m;
int main(void)
{
    cin >> n >> m;
    int st = 0;
    for (int i = 0; i < n; i++) {
        int l, s;
        cin >> l >> s;
        for (int j = st; j <= st + l; j++) lim[j] = s;
        st += l;
    }
    st = 0;
    for (int i = 0; i < m; i++) {
        int l, s;
        cin >> l >> s;
        for (int j = st; j <= st + l; j++) speed[j] = s;
        st += l;
    }
    for (int i = 0; i <= 100; i++) ans = max(ans, speed[i] - lim[i]);
    cout << ans;
    return 0;
}