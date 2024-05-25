#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
int n, m, l, dist[205][205], res[205], ans = INF;
vector<int> mem;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	fill(&dist[0][0], &dist[201][0], INF);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1;j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	cin >> l;
	for (int i = 1; i <= l; i++) {
		int p;
		cin >> p;
		mem.push_back(p);
	}

	for (int i = 1; i <= n; i++) {
		for (int x : mem) res[i] = max(res[i], dist[x][i] + dist[i][x]);
		ans = min(ans, res[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (res[i] == ans) cout << i << ' ';
	}
}