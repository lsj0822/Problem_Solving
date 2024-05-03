#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, ans[100005];
vector<int> node[100005];
vector<bool> vst(100005);
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	queue<int> Q;
	Q.push(1);
	vst[1] = 1;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int v : node[cur]) {
			if (vst[v]) continue;
			ans[v] = cur;
			Q.push(v);
			vst[v] = 1;
		}
	}
	for (int i = 2; i <= n; i++) cout << ans[i] << '\n';
}