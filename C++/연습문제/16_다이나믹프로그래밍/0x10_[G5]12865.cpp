#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, k, ans[105][100005], weight, value;
pair<int, int> ks[105];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> weight >> value;
		ks[i] = { weight, value };
	}
	for (int i = 1; i <= n; i++) { 
		for (int w = 1; w <= k; w++) { 
			if (w - ks[i].X >= 0) ans[i][w] = max(ans[i-1][w], ans[i - 1][w - ks[i].X] + ks[i].Y);
			else ans[i][w] = ans[i - 1][w];
		}
	}
	cout << ans[n][k];
}