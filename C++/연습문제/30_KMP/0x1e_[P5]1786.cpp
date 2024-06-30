#include<iostream>
#include<string>
#include<vector>
using namespace std;
string t, p;
vector<int> idx;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	getline(cin, t); getline(cin, p);
	vector<int> f((int)p.size());
	int j = 0;
	for (int i = 1; i < (int)p.size(); i++) {
		while (j > 0 && p[i] != p[j]) j = f[j - 1];
		if (p[i] == p[j]) f[i] = ++j;
	}
	j = 0;
	for (int i = 0; i < (int)t.size(); i++) {
		while (j > 0 && t[i] != p[j]) j = f[j - 1];
		if (t[i] == p[j]) j++;
		if (j == (int)p.size()) {
			idx.push_back(i - j + 2);
			j = f[j - 1];
		}
	}
	cout << (int)idx.size() << '\n';
	for (int v : idx) cout << v << ' ';
}