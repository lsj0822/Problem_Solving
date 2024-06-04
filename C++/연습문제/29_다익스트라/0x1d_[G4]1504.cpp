#include<bits/stdc++.h>
using namespace std;
const int INF = 1e7;
int n, e, v1, v2, dist[1005];
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
	cin >> n >> e;
	while (e--) {
		int a, b, t;
		cin >> a >> b >> t;
		node[a].push_back({ t,b });
		node[b].push_back({ t,a });
	}
	cin >> v1 >> v2;
	int ans = min(dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n), dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n));
	if (ans >= INF) ans = -1;
	cout << ans;
}