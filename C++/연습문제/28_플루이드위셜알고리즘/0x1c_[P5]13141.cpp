#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n, m, dist[205][205], road[205][205], flame[205][205], ans = INF;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	fill(&dist[0][0], &dist[201][0], INF);
	for (int i = 0; i < m; i++) {
		int a, b, c, u, v;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c * 2);
		dist[b][a] = dist[a][b];
		u = min(a, b); v = max(a, b);
		road[u][v] = max(road[u][v], c*2);
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		int res = -1, mint, maxt;
		fill(&flame[0][0], &flame[201][0], -1);
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (road[i][j] == 0) continue;
				mint = min(dist[k][i], dist[k][j]); maxt = max(dist[k][i], dist[k][j]);
				flame[i][j] = mint + road[i][j];
				if ((maxt - mint) < road[i][j]) flame[i][j] -= (road[i][j] - maxt + mint) / 2;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				res = max(res, flame[i][j]);
			}
		}
		ans = min(ans, res);
	}
	cout << fixed << setprecision(1) << ans / 2.;
}