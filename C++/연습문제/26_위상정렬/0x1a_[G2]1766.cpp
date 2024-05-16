#include<bits/stdc++.h>
using namespace std;
vector<int> adj[32005];
int deg[32005], n, m;
priority_queue<int, vector<int> , greater<int>> Q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		deg[v]++;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) Q.push(i);
	}
	while (!Q.empty()) {
		int cur = Q.top(); Q.pop();
		cout << cur << ' ';
		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) Q.push(nxt);
		}
	}
}