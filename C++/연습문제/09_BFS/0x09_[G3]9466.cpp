#include <bits/stdc++.h>
using namespace std;
vector<int> match(100005);
vector<bool> done(100005), vst(100005);
int n, t, res;
void DFS(int x) {
	vst[x] = 1;
	int nxt = match[x];
	if (!vst[nxt]) {
		DFS(nxt);
	}
	if(!done[nxt]) {
		for (int i = nxt; i != x; i = match[i]) {
			res--;
		}
		res--;
	}
	done[x] = 1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		fill(match.begin(), match.end(), 0);
		fill(done.begin(), done.end(), 0);
		fill(vst.begin(), vst.end(), 0);
		cin >> n;
		res = n;
		for (int i = 1; i <= n; i++) cin >> match[i];
		for (int i = 1; i <= n; i++) {
			if (vst[i]) continue;
			DFS(i);
		}
		cout << res << '\n';
	}
}