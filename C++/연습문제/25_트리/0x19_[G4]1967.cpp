#include <bits/stdc++.h>
using namespace std;
int n, ans = -1;
vector<pair<int,int>> node[100005];
int DFS(int n) {
	int first = 0, second = 0;
	for (auto v : node[n]) {
		int dist = DFS(v.first) + v.second;
		if (dist > first) {
			second = first;
			first = dist;
		}
		else if (dist > second) second = dist;
	}
	ans = max(ans, first + second);
	return first;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v, d;
		cin >> u;
		while (1) {
			cin >> v;
			if (v == -1) break;
			cin >> d;
			node[u].push_back({ v,d });
		}
	}
	DFS(1);
	cout << ans;
}