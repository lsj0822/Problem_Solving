#include<bits/stdc++.h>
using namespace std;
int n, cnt = 0;
long long ans = 0;
vector<int> g(100005, -1);
tuple<int, int, int, int> pos[100005]; //x,y,z,index
vector<tuple<int, int, int>> edge;
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
int find(int x) {
	if (g[x] < 0) return x;
	return g[x] = find(g[x]);
}
bool is_diff_group(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return 0;
	if (g[u] <= g[v]) g[v] = u;
	else g[u] = v;
	return 1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		pos[i] = { x,y,z,i};
	}
	pos_sort(0);
	for (int i = 2; i <= n; i++) edge.push_back({ get<0>(pos[i]) - get<0>(pos[i - 1]),get<3>(pos[i]),get<3>(pos[i - 1]) });
	pos_sort(1);
	for (int i = 2; i <= n; i++) edge.push_back({ get<1>(pos[i]) - get<1>(pos[i - 1]),get<3>(pos[i]),get<3>(pos[i - 1]) });
	pos_sort(2);
	for (int i = 2; i <= n; i++) edge.push_back({ get<2>(pos[i]) - get<2>(pos[i - 1]),get<3>(pos[i]),get<3>(pos[i - 1]) });
	sort(edge.begin(), edge.end());
	for (auto cur : edge) {
		int c, a, b;
		tie(c, a, b) = cur;
		if (!is_diff_group(a, b)) continue;
		cnt++;
		ans += c;
		if (cnt == n - 1) break;
	}
	cout << ans;
}