#include<bits/stdc++.h>
using namespace std;
int n, m, k;
const int INF = 1e8;
priority_queue<int> dist[1005];
vector<pair<int, int>> adj[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dist[i].push(INF);
		}
	}
	dist[1].pop();
	dist[1].push(0);
	pq.push({ 0,1 });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		for (auto nxt : adj[cur.second]) {
			int w = cur.first + nxt.first;
			if (w >= dist[nxt.second].top()) continue;
			dist[nxt.second].pop();
			dist[nxt.second].push(w);
			pq.push({ w,nxt.second });
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i].top() == INF) cout << -1;
		else cout << dist[i].top();
		cout << '\n';
	}
}
