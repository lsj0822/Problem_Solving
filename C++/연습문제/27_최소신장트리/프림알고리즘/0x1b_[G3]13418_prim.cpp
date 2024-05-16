#include<bits/stdc++.h>
using namespace std;
int v, e, cnt = 0, ans[2] = {0,};
priority_queue<tuple<int, int, int>> max_pq;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> min_pq;
vector<pair<int, int>> adj[1005];
bool vst[1005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i <= e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}
	vst[0] = 1;
	for (auto nxt : adj[0]) {
		max_pq.push({ nxt.first, 0, nxt.second });
		min_pq.push({ nxt.first, 0, nxt.second });
	}
	while (cnt < v) {
		int a, b, c;
		tie(c, a, b) = max_pq.top(); max_pq.pop();
		if (vst[b]) continue;
		cnt++;
		vst[b] = 1;
		ans[0] += 1-c;
		for (auto nxt : adj[b]) max_pq.push({ nxt.first, b, nxt.second });
	}
	fill(&vst[0], &vst[v+1], 0);
	cnt = 0; vst[0] = 1;
	while (cnt < v) {
		int a, b, c;
		tie(c, a, b) = min_pq.top(); min_pq.pop();
		if (vst[b]) continue;
		cnt++;
		vst[b] = 1;
		ans[1] += 1-c;
		for (auto nxt : adj[b]) min_pq.push({ nxt.first, b, nxt.second });
	}
	cout << ans[1]*ans[1] - ans[0]*ans[0];
}