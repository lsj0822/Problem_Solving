#include <bits/stdc++.h>
using namespace std;
int t, n, k, w;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		vector<int> adj[1005], res(1005);
		int d[1005], deg[1005] = { 0, };
		queue<int> Q;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> d[i];
		for (int i = 0; i < k; i++) {
			int u, v;
			cin >> u >> v;
			deg[v]++;
			adj[u].push_back(v);
		}
		cin >> w;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 0) Q.push(i);
			res[i] = d[i];
		}
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			if (cur == w) {
				cout << res[w] << '\n';
				break;
			}
			for (int nxt : adj[cur]) {
				deg[nxt]--;
				if (deg[nxt] == 0) Q.push(nxt);
				res[nxt] = max(res[nxt], res[cur] + d[nxt]);
			}
		}
	}
}