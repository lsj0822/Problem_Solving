#include<bits/stdc++.h>
using namespace std;
int n, m, hack, maxhack = -1;
vector<int> trust[10005], result[10005];
vector<bool> vst(10005, false);
queue<int> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		trust[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		hack = 1;
		fill(vst.begin(), vst.end(), 0);
		Q.push(i);
		vst[i] = 1;
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (int c : trust[cur]) {
				if (vst[c]) continue;
				vst[c] = 1;
				Q.push(c);
				hack++;
			}
		}
		result[hack].push_back(i);
		maxhack = max(maxhack, hack);
	}
	for (int c : result[maxhack]) cout << c << ' ';
}