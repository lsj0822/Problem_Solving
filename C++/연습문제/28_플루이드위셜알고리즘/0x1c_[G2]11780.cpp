#include<iostream>
#include<vector>
using namespace std;
const int INF = 1000000000;
int n, m, dist[105][105], nxt[105][105];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	fill(&dist[0][0], &dist[101][0], INF);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		nxt[a][b] = b;
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) dist[i][j] = 0;
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == 0) cout << 0;
			else {
				vector<int> path;
				int st = i;
				while (st != j) {
					path.push_back(st);
					st = nxt[st][j];
				}
				path.push_back(j);
				cout << path.size() << ' ';
				for (int x : path) cout << x << ' ';
			}
			cout << '\n';
		}
	}
}