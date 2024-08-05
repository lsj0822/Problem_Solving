#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int dp[105][105][105], alen, blen, clen;
string a, b, c;
int main() {
	cin >> a >> b >> c;
	alen = (int)a.length(); blen = (int)b.length(); clen = (int)c.length();
	for (int i = 0; i < alen; i++) {
		for (int j = 0; j < blen; j++) {
			for (int k = 0; k < clen; k++) {
				if (a[i] == b[j] && b[j] == c[k]) dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
				else dp[i + 1][j + 1][k + 1] = max({ dp[i + 1][j + 1][k], dp[i + 1][j][k + 1], dp[i][j + 1][k + 1] });
			}
		}
	}
	cout << dp[alen][blen][clen];
}