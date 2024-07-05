#include<iostream>
#include<string>
using namespace std;
string num[10005];
const int ROOT = 1, MX = 100005;
int nxt[MX][10], t, n, idx;
bool ans, vst[MX];
int c2i(char c) {
	return c - '0';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n; ans = true; idx = 2;
		fill(&nxt[0][0], &nxt[MX][0], -1);
		fill(&vst[0], &vst[MX], 0);
		for (int i = 0; i < n; i++) cin >> num[i];
		for (int i = 0; i < n; i++) {
			int cur = ROOT;
			for (char c : num[i]) {
				if (nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = idx++;
				cur = nxt[cur][c2i(c)];
			}
			vst[cur] = 1;
		}
		for (int i = 0; i < n; i++) {
			if (!ans) break;
			int cur = ROOT;
			for (char c : num[i]) {
				if (vst[cur]) {
					ans = false;
					break;
				}
				cur = nxt[cur][c2i(c)];
			}
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
}