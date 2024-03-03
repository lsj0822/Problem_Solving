#include <bits/stdc++.h>
using namespace std;
int t,s,e;
char c[4] = { 'D','S','L','R' };
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		string r;
		int vst[10005];
		memset(vst, 0, sizeof(vst));
		cin >> s >> e;
		queue<pair<int,string>> Q;
		vst[s] = 1;
		Q.push({ s,"" });
		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			if (cur.first == e) {
				cout << cur.second << '\n';
				break;
			}
			for (int i = 0; i < 4; i++) {
				if (i == 0) {
					int dnxt = (cur.first * 2) % 10000;
					if (vst[dnxt] == 0) {
						vst[dnxt] = 1;
						Q.push({ dnxt,cur.second + "D" });
					}
				}
				if (i == 1) {
					int snxt = (cur.first + 9999) % 10000;
					if (vst[snxt] == 0) {
						vst[snxt] = 1;
						Q.push({ snxt,cur.second + "S" });
					}
				}
				if (i == 2) {
					int lnxt = (cur.first % 1000) * 10 + (cur.first / 1000);
					if (vst[lnxt] == 0) {
						vst[lnxt] = 1;
						Q.push({ lnxt,cur.second + "L" });
					}
				}
				if (i == 3) {
					int rnxt = (cur.first % 10)*1000 + (cur.first / 10);
					if (vst[rnxt] == 0) {
						vst[rnxt] = 1;
						Q.push({ rnxt,cur.second + "R" });
					}
				}
			}
		}
	}
}