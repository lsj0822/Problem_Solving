#include<bits/stdc++.h>
using namespace std;
int v, e, ans = 0, cnt = 0;
vector<pair<int, int>> adj[55];
bool vst[55];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie();
	while (1) {
		while (!Q.empty()) Q.pop();
		for (int i = 1; i <= 51; i++) adj[i].clear();
		fill(&vst[0], &vst[55], 0);
		cin >> v;
		if (v == 0) return 0;
		cin >> e;
		ans = 0; cnt = 0;
		for (int i = 0; i < e; i++) {
			int cost, a, b;
			cin >> a >> b >> cost;
			adj[a].push_back({ cost,b });
			adj[b].push_back({ cost,a });
		}
		vst[1] = 1;
		for (auto nxt : adj[1]) Q.push({ nxt.first, 1, nxt.second });
		while (cnt < v - 1) {
			int c, a, b;
			tie(c, a, b) = Q.top(); Q.pop();
			if (vst[b]) continue;
			cnt++;
			ans += c;
			vst[b] = 1;
			for (auto nxt : adj[b]) {
				if (!vst[nxt.second]) Q.push({ nxt.first, b, nxt.second });
			}
		}
		cout << ans << '\n';
	}
}