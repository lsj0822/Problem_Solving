#include<bits/stdc++.h>
using namespace std;
vector<int> node[100005], score(100005), weight(100005);
vector<bool> vst(100005);
int n, m, boss;
void calc(int cur, int w) {
	vst[cur] = 1;
	for (int v : node[cur]) {
		if (vst[v]) continue;
		score[v] = w + weight[v];
		calc(v, w+weight[v]);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		if (k == -1) boss = i;
		else node[k].push_back(i);
	}
	for (int t = 0; t < m; t++) {
		int i, w;
		cin >> i >> w;
		weight[i] += w;
	}
	calc(boss, 0);
	for (int i = 1; i <= n; i++) cout << score[i] << ' ';
}