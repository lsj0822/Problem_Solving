#include<bits/stdc++.h>
using namespace std;
int n, m, break_node = 0, added_node = -1;
vector<int> node[100005];
vector<bool> vst(100005), cycle(100005);
void DFS(int cur, int parent) {
	vst[cur] = 1;
	for (int v : node[cur]) {
		if (v == parent) continue;
		if (vst[v]) {
			if(!cycle[v]) break_node++;
			continue;
		}
		DFS(v, cur);
	}
	cycle[cur] = 1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (vst[i]) continue;
		DFS(i, -1);
		added_node++;
	}
	cout << added_node + break_node;
}