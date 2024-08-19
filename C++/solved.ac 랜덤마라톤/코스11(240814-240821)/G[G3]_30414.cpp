#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int n, p, mount[100005];
vector<int> node[100005];
vector<bool> vst(100005);
int DFS(int cur) {
	int tmp = mount[cur];
	vst[cur] = 1;
	for (int v : node[cur]) {
		if (vst[v]) continue;
		tmp += DFS(v);
	}
	if (tmp > 0) return 0;
	else return tmp;
}
int main() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> mount[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		mount[i] -= k;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	cout << -DFS(p);
}