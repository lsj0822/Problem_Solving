#include<bits/stdc++.h>
using namespace std;
int n, cnt = 0;
long long ans = 0;
tuple<int, int, int, int> pos[100005]; // x,y,z,index
vector<pair<int, int>> adj[100005];
vector<bool> vst(100005);
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
bool pos_sort_x(tuple<int, int, int, int> a, tuple<int, int, int, int> b) { return get<0>(a) < get<0>(b); }
bool pos_sort_y(tuple<int, int, int, int> a, tuple<int, int, int, int> b) { return get<1>(a) < get<1>(b); }
bool pos_sort_z(tuple<int, int, int, int> a, tuple<int, int, int, int> b) { return get<2>(a) < get<2>(b); }
void pos_sort(int type) {
	switch (type) {
	case 0: sort(&pos[1], &pos[n + 1], pos_sort_x); break;
	case 1:	sort(&pos[1], &pos[n + 1], pos_sort_y); break;
	case 2:	sort(&pos[1], &pos[n + 1], pos_sort_z); break;
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		pos[i] = { x,y,z,i };
	}
	pos_sort(0);
	for (int i = 2; i <= n; i++) {
		int x1 = get<3>(pos[i]), x2 = get<3>(pos[i - 1]), dist = get<0>(pos[i]) - get<0>(pos[i - 1]);
		adj[x2].push_back({ dist, x1 });
		adj[x1].push_back({ dist, x2 });
	}
	pos_sort(1);
	for (int i = 2; i <= n; i++) {
		int y1 = get<3>(pos[i]), y2 = get<3>(pos[i - 1]), dist = get<1>(pos[i]) - get<1>(pos[i - 1]);
		adj[y2].push_back({ dist, y1 });
		adj[y1].push_back({ dist, y2 });
	}
	pos_sort(2);
	for (int i = 2; i <= n; i++) {
		int z1 = get<3>(pos[i]), z2 = get<3>(pos[i - 1]), dist = get<2>(pos[i]) - get<2>(pos[i - 1]);
		adj[z2].push_back({ dist, z1 });
		adj[z1].push_back({ dist, z2 });
	}
	vst[1] = 1;
	for (auto nxt : adj[1]) pq.push({ nxt.first, 1, nxt.second });
	while (cnt < n-1) {
		auto cur = pq.top(); pq.pop();
		int c, a, b;
		tie(c, a, b) = cur;
		if (vst[b]) continue;
		vst[b] = 1;
		cnt++;
		ans += c;
		for (auto nxt : adj[b]) if (!vst[nxt.second]) pq.push({ nxt.first, b, nxt.second });
	}
	cout << ans;
}