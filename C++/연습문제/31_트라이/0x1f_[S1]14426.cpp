#include<iostream>
#include<string>
using namespace std;
const int MX = 500 * 10000 + 5, ROOT = 1;
int n, m, nxt[MX][26], ans = 0, idx = 2;
string str;
int c2i(char c) {
	return c - 'a';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&nxt[0][0], &nxt[MX][0], -1);
	cin >> n >> m;
	while (n--) {
		cin >> str;
		int cur = ROOT;
		for (char c : str) {
			if (nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = idx++;
			cur = nxt[cur][c2i(c)];
		}
	}
	while (m--) {
		cin >> str;
		int cur = ROOT;
		bool is_find = true;
		for (char c : str) {
			if (nxt[cur][c2i(c)] == -1) {
				is_find = false;
				break;
			}
			cur = nxt[cur][c2i(c)];
		}
		if (is_find) ans++;
	}
	cout << ans;
}