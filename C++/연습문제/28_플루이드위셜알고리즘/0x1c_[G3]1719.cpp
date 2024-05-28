#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n, m, dist[205][205], nxt[205][205];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&dist[0][0], &dist[201][0], INF);
	cin >> n >> m;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		dist[u][v] = min(dist[u][v], c);
		dist[v][u] = dist[u][v];
		nxt[u][v] = v; nxt[v][u] = u;
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int crit = dist[i][k] + dist[k][j];
				if (crit < dist[i][j]) {
					dist[i][j] = crit;
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (nxt[i][j] == 0) cout << "- ";
			else cout << nxt[i][j] << ' ';
		}
		cout << '\n';
	}
}