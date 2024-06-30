#include<iostream>
#include<string>
#include<vector>
using namespace std;
string s, news, k;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s >> k;
	for (char c : s) {
		if (c >= '0' && c <= '9') continue;
		news += c;
	}
	vector<int> f((int)k.size());
	int j = 0;
	for (int i = 1; i < (int)k.size(); i++) {
		while (j > 0 && k[i] != k[j]) j = f[j - 1];
		if (k[i] == k[j]) f[i] = ++j;
	}
	j = 0;
	for (int i = 0; i < (int)news.size(); i++) {
		while (j > 0 && news[i] != k[j]) j = f[j - 1];
		if (news[i] == k[j]) j++;
		if (j == (int)k.size()) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}