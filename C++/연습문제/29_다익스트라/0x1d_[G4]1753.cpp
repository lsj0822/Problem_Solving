#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int v, e, k, dist[20005];
vector<pair<int,int>> node[20005];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> route;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> e >> k;
	fill(&dist[0], &dist[20005], INF);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		node[u].push_back({ w,v });
	}
	dist[k] = 0;
	route.push({ 0,k });
	while (!route.empty()) {
		auto cur = route.top(); route.pop();
		if (cur.first != dist[cur.second]) continue;
		for (auto nxt : node[cur.second]) {
			int weight = cur.first + nxt.first;
			if (weight >= dist[nxt.second]) continue;
			dist[nxt.second] = weight;
			route.push({ weight, nxt.second });
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}