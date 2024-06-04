#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e12;
int n, m;
ll dist[100005];
vector<pair<int, int>> adj[100005];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	fill(&dist[0], &dist[n + 1], INF);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back({ i,b });
		adj[b].push_back({ i,a });
	}
	dist[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (cur.first != dist[cur.second]) continue;
		for (auto nxt : adj[cur.second]) {
			ll w;
			if (nxt.first >= (cur.first % m)) w = (cur.first / m) * m + nxt.first;
			else w = ((cur.first / m) + 1) * m + nxt.first;
			if (w >= dist[nxt.second]) continue;
			dist[nxt.second] = w;
			pq.push({w,nxt.second });
		}
	}
	cout << dist[n] + 1;
}