#include<bits/stdc++.h>
using namespace std;
int v, e, cnt = 0, ans = 0, mx = -1;
vector<pair<int, int>> adj[100005];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
bool vst[100005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}
	vst[1] = 1;
	for (auto nxt : adj[1]) pq.push({ nxt.first, 1, nxt.second });
	while (cnt < v - 1) {
		int c, a, b;
		tie(c, a, b) = pq.top(); pq.pop();
		if (vst[b]) continue;
		cnt++;
		ans += c;
		mx = max(mx, c);
		vst[b] = 1;
		for (auto nxt : adj[b]) {
			if (!vst[nxt.second]) pq.push({ nxt.first,b,nxt.second });
		}
	}
	cout << ans - mx;
}