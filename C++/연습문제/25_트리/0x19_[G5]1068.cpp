#include<bits/stdc++.h>
using namespace std;
int n, r, root, ans = 0;
vector<int> node[55];
void DFS(int n) {
	if (n == r) return;
	if (node[n].size() == 0 || (node[n].size() ==1 && node[n][0] == r)) {
		ans++;
		return;
	}
	for (int v : node[n]) {
		DFS(v);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k != -1) node[k].push_back(i);
		else root = i;
	}
	cin >> r;
	node[r].clear();
	DFS(root);
	cout << ans;
}