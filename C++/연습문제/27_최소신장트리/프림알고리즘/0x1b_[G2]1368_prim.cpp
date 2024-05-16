#include<bits/stdc++.h>
using namespace std;
int v, e = 0, ans = 0, cnt = 0;
bool vst[10005];
vector<pair<int, int>> adj[10005];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v;
	for (int i = 1; i <= v; i++) {
		int cost;
		cin >> cost;
		adj[v + 1].push_back({ cost,i });
		adj[i].push_back({ cost,v + 1 });
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			int cost;
			cin >> cost;
			if (i == j) continue;
			adj[i].push_back({ cost,j });
		}
	}
	vst[1] = 1;
	for (auto nxt : adj[1]) pq.push({ nxt.first, 1, nxt.second });
	while (cnt < v) {
		int cost, a, b;
		tie(cost, a, b) = pq.top(); pq.pop();
		if (vst[b]) continue;
		cnt++;
		ans += cost;
		vst[b] = 1;
		for (auto nxt : adj[b]) {
			if (!vst[nxt.second]) pq.push({ nxt.first,b,nxt.second });
		}
	}
	cout << ans;
}