#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

unsigned int dp[1005][1005];
int t;
int main(void)
{
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[3][1] = 1;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 2; j <= i; j++) {
            for (int d = 1; d <= 3; d++) {
                if (i - d > 0) dp[i][j] = (dp[i][j] + dp[i - d][j - 1]) % MOD;
            }
        }
    }
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }
    return 0;
}