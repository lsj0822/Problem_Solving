#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
int n, m, k, ct[100005];
long long dist[100005];
pair<long long, int> ans = { -1,0 };
vector<pair<int, int>> node[100005];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
void dijkstra() {
	fill(&dist[0], &dist[n + 1], INF);
	for (int i = 0; i < k; i++) {
		dist[ct[i]] = 0;
		pq.push({ 0,ct[i] });
	}
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (cur.first != dist[cur.second]) continue;
		for (auto nxt : node[cur.second]) {
			long long w = cur.first + nxt.first;
			if (w >= dist[nxt.second]) continue;
			dist[nxt.second] = w;
			pq.push({ w,nxt.second });
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		node[v].push_back({ c,u });
	}
	for (int i = 0; i < k; i++) cin >> ct[i];
	dijkstra();
	for (int i = 1; i <= n; i++) if (ans.first < dist[i]) ans = { dist[i], i };
	cout << ans.second << '\n' << ans.first;
}