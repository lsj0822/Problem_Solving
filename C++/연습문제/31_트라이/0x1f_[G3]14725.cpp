#include<iostream>
#include<string>
#include<map>
using namespace std;
const int MX = 15005, ROOT = 0;
map<string, int> nxt[MX];
int n, t, unused = 1, dep[MX];
string name[MX];
void print(int idx) {
	for (auto cur : nxt[idx]) {
		int info = cur.second;
		for (int i = 0; i < dep[info]; i++) cout << "--";
		cout << name[info] << '\n';
		print(info);
	}
}
int main() {
	cin >> n;
	while (n--) {
		cin >> t;
		int cur = ROOT;
		for (int d = 0; d < t; d++) {
			string str;
			cin >> str;
			if (nxt[cur][str] == 0) nxt[cur][str] = unused++;
			dep[nxt[cur][str]] = d;
			name[nxt[cur][str]] = str;
			cur = nxt[cur][str];
		}
	}
	print(ROOT);
}