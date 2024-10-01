#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX_SIZE = 1e5 + 5;
int n, m, k, s;
int cost[MAX_SIZE], dist[MAX_SIZE], zcity[MAX_SIZE], inn[2];
long long ans[MAX_SIZE];
bool zombie[MAX_SIZE];
vector<int> adj[MAX_SIZE];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> route;
void BFS() {
	queue<int> Q;
	for (int i = 0; i < k; i++) {
		Q.push(zcity[i]);
		dist[zcity[i]] = 0;
	}
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int nxt : adj[cur]) {
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}
}

void dijkstra() {
	ans[1] = 0;
	cost[1] = 0; cost[n] = 0;
	route.push({ 0,1 });
	while (!route.empty()) {
		auto cur = route.top(); route.pop();
		if (cur.first != ans[cur.second]) continue;
		for (int nxt : adj[cur.second]) {
			if (zombie[nxt]) continue;
			long long weight = cur.first + cost[nxt];
			if (weight >= ans[nxt]) continue;
			ans[nxt] = weight;
			route.push({ weight,nxt });
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k >> s;
	fill(&dist[0], &dist[n + 1], -1);
	fill(&ans[0], &ans[n + 1], 1e15);
	cin >> inn[0] >> inn[1];
	for (int i = 0; i < k; i++) {
		cin >> zcity[i];
		zombie[zcity[i]] = 1;
	}
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	BFS();
	for (int i = 1; i <= n; i++) cost[i] = (dist[i] > s ? inn[0] : inn[1]);
	dijkstra();
	cout << ans[n];
}