#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int INF = 1e9;
int n, m, dist[1005], st, en;
vector<pair<int, int>> node[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	fill(&dist[0], &dist[1001], INF);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ c,b });
	}
	cin >> st >> en;
	dist[st] = 0;
	pq.push({ 0,st });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (dist[cur.y] != cur.x) continue;
		for (auto nxt : node[cur.y]) {
			int w = cur.x + nxt.x;
			if (w >= dist[nxt.y]) continue;
			dist[nxt.y] = w;
			pq.push({ w,nxt.y });
		}
	}
	cout << dist[en];
}