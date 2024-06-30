#include<iostream>
#include<vector>
#include<string>
using namespace std;
string s, p;
int main() {
	cin >> s >> p;
	vector<int> f(p.size());
	int j = 0;
	for (int i = 1; i < p.size(); i++) {
		while (j > 0 && p[i] != p[j]) j = f[j-1];
		if (p[i] == p[j]) f[i] = ++j;
	}
	j = 0;
	for (int i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != p[j]) j = f[j - 1];
		if (s[i] == p[j]) j++;
		if (j == p.size()) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}