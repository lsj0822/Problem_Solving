#include <iostream>
using namespace std;

int n, m, ans = 0;
int board[105][105];
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = m; j > 0; j--) {
            if (board[i][j] == 0) continue;
            ans++;
            for (int x = 1; x <= i; x++) {
                for (int y = 1; y <= j; y++) {
                    board[x][y] = 1 - board[x][y];
                }
            }
        }
    }
    cout << ans;
    return 0;
}