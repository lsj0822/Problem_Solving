#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, s, e, dist[1005], pre_node[1005];
vector<pair<int, int>> node[1005];
vector<int> ans;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> route;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	fill(&dist[0], &dist[1001], INF);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		node[u].push_back({ w,v });
	}
	cin >> s >> e;
	dist[s] = 0;
	route.push({ 0,s });
	while (!route.empty()) {
		auto cur = route.top(); route.pop();
		if (cur.first != dist[cur.second]) continue;
		for (auto nxt : node[cur.second]) {
			int weight = cur.first + nxt.first;
			if (weight >= dist[nxt.second]) continue;
			dist[nxt.second] = weight;
			pre_node[nxt.second] = cur.second;
			route.push({ weight, nxt.second });
		}
	}
	int cur = e;
	while (cur != s) {
		ans.push_back(cur);
		cur = pre_node[cur];
	}
	ans.push_back(s);
	reverse(ans.begin(), ans.end());
	cout << dist[e] << '\n' << ans.size() << '\n';
	for (int a : ans) cout << a << ' ';
}