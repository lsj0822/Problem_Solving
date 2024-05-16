#include<bits/stdc++.h>
using namespace std;
int v, e, cnt = 0;
long long ans = 0;
vector<pair<int, int>> adj[10005];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
bool vst[10005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			int c;
			cin >> c;
			if (i == j) continue;
			adj[i].push_back({ c,j });
		}
	}
	vst[1] = 1;
	for (auto nxt : adj[1]) pq.push({ nxt.first, 1, nxt.second });
	while (cnt < v-1) {
		int c,a,b;
		tie(c,a,b) = pq.top(); pq.pop();
		if (vst[b]) continue;
		cnt++;
		ans += c;
		vst[b] = 1;
		for (auto nxt : adj[b]) {
			if (!vst[nxt.second]) pq.push({ nxt.first, b, nxt.second });
		}
	}
	cout << ans;
}