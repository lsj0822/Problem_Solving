#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MX = 1005, ROOT = 0;
int nxt[MX][2], unused = 1, n, arr[MX];
string ans[MX];
pair<int, int> cparr[MX];
bool vst[MX];
bool DFS(string str, int idx, int cur) {
	if (str.size() == cparr[idx].first) {
		ans[cparr[idx].second] = str;
		vst[cur] = 1;
		return true;
	}
	for (int i : {0, 1}) {
		if (vst[nxt[cur][i]]) continue;
		if (nxt[cur][i] == -1) nxt[cur][i] = unused++;
		if (DFS(str + to_string(i), idx, nxt[cur][i])) return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&nxt[0][0], &nxt[MX - 1][0], -1);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		cparr[i] = { arr[i], i };
	}
	sort(&cparr[0], &cparr[n]);
	for (int i = 0; i < n; i++) {
		if (!DFS("", i, ROOT)) {
			cout << -1;
			return 0;
		}
	}
	cout << 1 << '\n';
	for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}