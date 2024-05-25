#include <bits/stdc++.h>
using namespace std;
int n, m, r, items[105], dist[105][105], ans = -1;
const int INF = 1000000000;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> r;
	fill(&dist[0][0], &dist[101][0], INF);
	for (int i = 1; i <= n; i++) cin >> items[i];
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		dist[a][b] = l; dist[b][a] = l;
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int total_item = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m) total_item += items[j];
		}
		ans = max(ans, total_item);
	}
	cout << ans;
}