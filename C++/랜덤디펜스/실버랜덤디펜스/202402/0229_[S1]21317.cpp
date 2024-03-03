#include <iostream>
using namespace std;
int n, jump[25][2], dp[25][2], k;
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int s, b;
        cin >> s >> b;
        jump[i][0] = s; jump[i][1] = b;
    }
    cin >> k;
    dp[1][1] = 1000000; dp[2][1] = 1000000; dp[3][1] = 1000000;
    dp[1][0] = 0;
    dp[2][0] = jump[1][0];
    dp[3][0] = min(jump[1][0] + jump[2][0], jump[1][1]);
    for (int i = 4; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0] + jump[i - 1][0], dp[i - 2][0] + jump[i - 2][1]);
        dp[i][1] = min(dp[i - 3][0] + k, min(dp[i - 1][1] + jump[i - 1][0], dp[i - 2][1] + jump[i - 2][1]));
    }
    cout << min(dp[n][0], dp[n][1]);
    return 0;
}