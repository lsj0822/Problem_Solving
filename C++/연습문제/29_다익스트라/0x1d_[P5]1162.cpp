#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, k;
const ll INF = 1e12;
ll dist[10005][25], ans = INF;
vector<pair<int, int>> adj[10005];
priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&dist[0][0], &dist[10001][0], INF);
	cin >> n >> m >> k;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}
	dist[1][0] = 0;
	pq.push(make_tuple(0,0,1));
	while (!pq.empty()) {
		ll w;
		int pack, cur;
		tie(w, pack, cur) = pq.top(); pq.pop();
		if (dist[cur][pack] != w) continue;
		//package
		if (pack < k) {
			for (auto nxt : adj[cur]) {
				if (w >= dist[nxt.second][pack+1]) continue;
				dist[nxt.second][pack+1] = w;
				pq.push({ w, pack + 1, nxt.second });
			}
		}
		//common dijkstra
		for (auto nxt : adj[cur]) {
			ll tot = w + nxt.first;
			if (tot >= dist[nxt.second][pack]) continue;
			dist[nxt.second][pack] = tot;
			pq.push({ tot,pack,nxt.second });
		}
	}
	for (int i = 0; i <= k; i++) ans = min(ans, dist[n][i]);
	cout << ans;
}