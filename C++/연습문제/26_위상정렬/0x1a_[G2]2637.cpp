#include <bits/stdc++.h>
using namespace std;
int n, m, refer[105][3], res[105][105], deg[105] = { 0, };
vector<bool> isprim(105);
vector<pair<int,int>> adj[105];
queue<int> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, k;
		cin >> u >> v >> k;
		refer[i][0] = u; refer[i][1] = v; refer[i][2] = k;
		deg[u]++;
	}
	for (int i = 1; i <= n; i++) if (deg[i] == 0) isprim[i] = 1;
	fill(&deg[0], &deg[101], 0);
	for (int i = 0; i < m; i++) {
		int u = refer[i][0], v = refer[i][1], k = refer[i][2];
		if (isprim[v]) {
			res[u][v] += k;
		}
		else {
			adj[v].push_back({ u,k });
			deg[u]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (isprim[i]) continue;
		if (deg[i] == 0) Q.push(i);
	}
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (auto v : adj[cur]) {
			int nxt = v.first, cnt = v.second;
			deg[nxt]--;
			if (deg[nxt] == 0) Q.push(nxt);
			for (int i = 1; i <= n; i++) res[nxt][i] += res[cur][i] * cnt;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (isprim[i]) cout << i << ' ' << res[n][i] << '\n';
	}
}