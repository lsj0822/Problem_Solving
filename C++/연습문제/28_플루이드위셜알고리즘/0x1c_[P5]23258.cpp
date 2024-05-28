#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, q, dist[305][305][305];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	fill(&dist[0][0][0], &dist[301][0][0], INF);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dist[i][j][0];
			if (dist[i][j][0] == 0) dist[i][j][0] = INF;
		}
	}
	for (int i = 1; i <= n; i++) dist[i][i][0] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j][k] = min(dist[i][j][k - 1], dist[i][k][k - 1] + dist[k][j][k - 1]);
			}
		}
	}
	while (q--) {
		int c, s, e;
		cin >> c >> s >> e;
		c--;
		if (dist[s][e][c] == INF) dist[s][e][c] = -1;
		cout << dist[s][e][c] << '\n';
	}
}