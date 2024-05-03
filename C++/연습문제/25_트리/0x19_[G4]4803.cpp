#include <bits/stdc++.h>
using namespace std;
int n, m, t = 1;
bool res = true;
vector<int> vst(505);
vector<int> node[505];
void DFS(int cur, int prev) {
	for (int v : node[cur]) {
		if (v == prev) continue;
		if (vst[v]) {
			res = false;
			continue;
		}
		vst[v] = 1;
		DFS(v, cur);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	while (1) {
		int trees = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) node[i].clear();
		fill(vst.begin(), vst.end(), false);
		if (n == 0 && m == 0) return 0;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			node[a].push_back(b);
			node[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (vst[i]) continue;
			res = true;
			vst[i] = 1;
			DFS(i, 0);
			if (res) trees++;
		}
		cout << "Case " << t << ": ";
		switch (trees) {
		case 1:
			cout << "There is one tree.\n";
			break;
		case 0:
			cout << "No trees.\n";
			break;
		default:
			cout << "A forest of " << trees << " trees.\n";
			break;
		}
		t++;
	}
}