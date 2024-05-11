#include <bits/stdc++.h>
using namespace std;
int n, m, nlen[1005][1005];
vector<int> node[1005];
vector<int> dist(1005);
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		node[u].push_back(v);
		node[v].push_back(u);
		nlen[u][v] = l;
		nlen[v][u] = l;
	}
	for (int i = 0; i < m; i++) {
		queue<int> Q;
		int res[1005];
		fill(dist.begin(), dist.end(), -1);
		int u, v;
		cin >> u >> v;
		Q.push(u);
		dist[u] = 0;
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			if (cur == v) {
				cout << dist[cur] << '\n';
				break;
			}
			for (int vec : node[cur]) {
				if (dist[vec] != -1) continue;
				dist[vec] = dist[cur] + nlen[cur][vec];
				Q.push(vec);
			}
		}
	}
}