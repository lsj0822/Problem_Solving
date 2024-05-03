#include<bits/stdc++.h>
using namespace std;
int n, r, q;
vector<int> node[100005], ans(100005);
vector<bool>vst(100005);
int DFS(int cur, int pre) {
	int res = 1;
	for (int v : node[cur]) {
		if (vst[v] || v == pre) continue;
		vst[v] = 1;
		res += DFS(v, cur);
	}
	ans[cur] = res;
	return res;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> r >> q;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	vst[r] = 1;
	DFS(r, -1);
	for (int i = 0; i < q; i++) {
		int k;
		cin >> k;
		cout << ans[k] << '\n';
	}
}