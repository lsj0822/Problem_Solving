#include<bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
vector<int> light[105], heavy[105];
vector<bool> vst(105, 0);
queue<int> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	int crit = (n + 1) / 2;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		heavy[a].push_back(b);
		light[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int heavy_cnt = 0, light_cnt = 0;
		fill(vst.begin(), vst.end(), 0);
		Q.push(i);
		vst[i] = 1;
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (int c : heavy[cur]) {
				if (vst[c]) continue;
				heavy_cnt++;
				Q.push(c);
				vst[c] = 1;
			}
		}
		fill(vst.begin(), vst.end(), 0);
		Q.push(i);
		vst[i] = 1;
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (int c : light[cur]) {
				if (vst[c]) continue;
				light_cnt++;
				Q.push(c);
				vst[c] = 1;
			}
		}
		if (heavy_cnt >= crit || light_cnt >= crit) ans++;
	}
	cout << ans;
}