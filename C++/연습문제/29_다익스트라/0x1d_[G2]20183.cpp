#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
using namespace std;
const ll INF = 1e15;
int n, m, a, b;
bool res = false;
ll dist[100005], c;
vector<pair<int, int>> adj[100005];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

bool dijkstra(int crit) {
	fill(&dist[0], &dist[n + 1], INF);
	dist[a] = 0;
	pq.push({ 0,a });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (cur.x != dist[cur.y]) continue;
		for (auto nxt : adj[cur.y]) {
			if (nxt.x > crit) continue;
			ll w = cur.x + nxt.x;
			if (w >= dist[nxt.y] || w > c) continue;
			dist[nxt.y] = w;
			pq.push({ w,nxt.y });
		}
	}
	return (dist[b] == INF ? false : true);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> a >> b >> c;
	while (m--) {
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
		adj[v].push_back({ w,u });
	}
	int st = 1, en = 1e9+1;
	while (st < en) {
		int mid = (st + en) / 2;
		if (dijkstra(mid)) {
			res = true;
			en = mid;
		}
		else st = mid + 1;
	}
	cout << (res ? en : -1);
}