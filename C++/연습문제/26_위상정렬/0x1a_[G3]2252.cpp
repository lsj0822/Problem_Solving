#include<bits/stdc++.h>
using namespace std;
vector<int> result, node[32005];
int deg[32005];
queue<int> Q;
int n, m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		deg[v]++;
		node[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) Q.push(i);
	}
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		result.push_back(cur);
		for (int v : node[cur]) {
			deg[v]--;
			if (deg[v] == 0) Q.push(v);
		}
	}
	for (int r : result) cout << r << ' ';
}