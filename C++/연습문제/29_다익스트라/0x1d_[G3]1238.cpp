#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, x, dist[1005], ans = -1;
vector<pair<int, int>> node[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> route;

int dijkstra(int st, int en) {
	fill(&dist[0], &dist[n + 1], INF);
	dist[st] = 0;
	route.push({ 0,st });
	while (!route.empty()) {
		auto cur = route.top(); route.pop();
		if (cur.first != dist[cur.second]) continue;
		for (auto nxt : node[cur.second]) {
			int w = cur.first + nxt.first;
			if (w >= dist[nxt.second]) continue;
			dist[nxt.second] = w;
			route.push({ w,nxt.second });
		}
	}
	return dist[en];
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> x;
	while (m--) {
		int a, b, t;
		cin >> a >> b >> t;
		node[a].push_back({ t,b });
	}
	for (int i = 1; i <= n; i++) ans = max(ans, dijkstra(i, x) + dijkstra(x, i));
	cout << ans;
}