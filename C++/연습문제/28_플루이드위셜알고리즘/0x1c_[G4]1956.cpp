#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int v, e, dist[405][405], ans = INF;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> e;
	fill(&dist[0][0], &dist[401][0], INF);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i < v; i++) {
		for (int j = i; j <= v; j++) {
			ans = min(ans, dist[i][j] + dist[j][i]);
		}
	}
	if (ans == INF) ans = -1;
	cout << ans;
}