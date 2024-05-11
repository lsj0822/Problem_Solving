#include<bits/stdc++.h>
using namespace std;
pair<int, int> ans = { 0,0 };
vector<int> level[10005], lnode(10005), rnode(10005), dist(10005), pos(10005);
int n, root;
int cnt(int node) {
	if (node == -1) return 0;
	int left_cnt = 0, right_cnt = 0;
	if (lnode[node] != -1) left_cnt = cnt(lnode[node]);
	if (rnode[node] != -1) right_cnt = cnt(rnode[node]);
	return 1 + left_cnt + right_cnt;
}
void find_pos(int node) {
	if (lnode[node] != -1) pos[lnode[node]] = pos[node] - cnt(rnode[lnode[node]]) - 1;
	if (rnode[node] != -1) pos[rnode[node]] = pos[node] + cnt(lnode[rnode[node]]) + 1;
	return;
}
void DFS(int node) {
	find_pos(node);
	level[dist[node]].push_back(pos[node]);
	if (lnode[node] != -1) {
		dist[lnode[node]] = dist[node] + 1;
		DFS(lnode[node]);
	}
	if (rnode[node] != -1) {
		dist[rnode[node]] = dist[node] + 1;
		DFS(rnode[node]);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		lnode[a] = b;
		rnode[a] = c;
	}
	for (int i = 1; i <= n; i++) if ((cnt(i)) == n) root = i;
	pos[root] = 0; dist[root] = 1;
	DFS(root);
	for (int i = 1; i <= n; i++) {
		if (level[i].size() == 0)break;
		sort(level[i].begin(), level[i].end());
		int length = (level[i][level[i].size() - 1] - level[i][0] + 1);
		if (length > ans.second) ans = { i, length };
	}
	cout << ans.first << ' ' << ans.second;
}