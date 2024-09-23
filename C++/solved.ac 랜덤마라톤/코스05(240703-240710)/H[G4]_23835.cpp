#include<iostream>
#include<vector>
using namespace std;
vector<int> adj[1005];
int n, q, ans[1005];
bool vst[1005];
bool DFS(int cur, int st, int en, int dep) {
	vst[cur] = 1;
	if (cur == en) {
		ans[cur] += dep;
		return true;
	}
	for (int i : adj[cur]) {
		if (vst[i]) continue;
		if (DFS(i, st, en, dep + 1)) {
			ans[cur] += dep;
			return true;
		}
	}
	return false;
}
int main() {
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		switch (t) {
		case 1:
			fill(&vst[0], &vst[n+1], 0);
			int u, v;
			cin >> u >> v;
			DFS(u, u, v, 0);
			break;
		case 2:
			int x;
			cin >> x;
			cout << ans[x] << '\n';
		}
	}
}