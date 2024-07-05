#include<iostream>
#include<string>
using namespace std;
const int MX = 1'000'005, ROOT = 1;
int n, nxt[MX][26], vst[MX], idx = 2;
string str;
int c2i(char c) {
	return c - 'a';
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		string nickname = "";
		int cur = ROOT;
		bool nicked = false;
		for (char c : str) {
			nickname += c;
			if (nxt[cur][c2i(c)] == 0) {
				if (!nicked) {
					cout << nickname;
					nicked = true;
				}
				nxt[cur][c2i(c)] = idx++;
			}
			cur = nxt[cur][c2i(c)];
		}
		if (vst[cur]) {
			cout << str << ++vst[cur];
			nicked = true;
		}
		else vst[cur] = 1;
		if (!nicked) cout << str;
		cout << '\n';
	}
}