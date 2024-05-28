#include <bits/stdc++.h>
using namespace std;
int n, m, k, dist[255][255];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&dist[0][0], &dist[251][0], 1000);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, b;
		cin >> u >> v >> b;
		dist[u][v] = 0;
		if (b) 	dist[v][u] = 0;
		else dist[v][u] = 1;
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int a = 1; a <= n; a++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][a] + dist[a][j]);
			}
		}
	}
	cin >> k;
	while (k--) {
		int u, v;
		cin >> u >> v;
		cout << dist[u][v] << '\n';
	}
}