#include<bits/stdc++.h>
using namespace std;
int v, e, k, cnt = 0, ans = 0;
vector<pair<int, int>> adj[1005];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
bool vst[1005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> e >> k;
	for (int i = 0; i < k; i++) {
		int p;
		cin >> p;
		pq.push({ 0,0,p });
	}
	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({ w,b });
		adj[b].push_back({ w,a });
	}
	while (cnt < v) {
		auto cur = pq.top(); pq.pop();
		int w, a, b;
		tie(w, a, b) = cur;
		if (vst[b]) continue;
		vst[b] = 1;
		cnt++;
		ans += w;
		for (auto nxt : adj[b]) if (!vst[nxt.second]) pq.push({ nxt.first, b, nxt.second });
	}
	cout << ans;
}