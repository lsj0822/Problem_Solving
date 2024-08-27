#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int INF = 1e9;
int n, m, q;
int dist[105][105][105];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&dist[0][0][0], &dist[101][0][0], INF);
	cin >> n >> m >> q;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		for(int i = 1; i <= n; i++) dist[u][v][i] = c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][i][j] = 0;
		}
	}
	for (int l = 1; l <= n; l++) {
		for (int k = 1; k <= n; k++) {
			if (l == k) continue;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dist[i][j][l] = min(dist[i][j][l], dist[i][k][l] + dist[k][j][l]);
				}
			}
		}
	}
	while (q--) {
		int s, k, e;
		cin >> s >> k >> e;
		cout << (dist[s][e][k] == INF ? "No" : to_string(dist[s][e][k])) << '\n';
	}
}