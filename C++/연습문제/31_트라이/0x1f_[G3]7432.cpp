#include<bits/stdc++.h>
using namespace std;
const int MX = 20005, ROOT = 0;
int n, unused = 1, dep[MX];
map<string, int> nxt[MX];
string dir_name[MX], str;
void print(int idx) {
	for (auto d : nxt[idx]) {
		int dir = d.second;
		for (int i = 0; i < dep[dir]; i++) cout << ' ';
		cout << dir_name[dir] << '\n';
		print(dir);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&dep[0], &dep[MX - 1], -1);
	cin >> n;
	while (n--) {
		cin >> str;
		stringstream ss(str);
		vector<string> ls;
		while (getline(ss, str, '\\')) ls.push_back(str);	
		int cur = ROOT;
		for (string s : ls) {
			if (nxt[cur][s] == 0) nxt[cur][s] = unused++;
			dep[nxt[cur][s]] = dep[cur] + 1;
			dir_name[nxt[cur][s]] = s;
			cur = nxt[cur][s];
		}
	}
	print(ROOT);
}