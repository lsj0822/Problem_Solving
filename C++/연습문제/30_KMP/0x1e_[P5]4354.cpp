#include<iostream>
#include<string>
#include<vector>
using namespace std;
string s;
int ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	while (s != ".") {
		int ss = (int)s.size();
		vector<int> f(ss);
		int j = 0, ans = 0;
		for (int i = 1; i < ss; i++) {
			while (j > 0 && s[i] != s[j]) j = f[j - 1];
			if (s[i] == s[j]) f[i] = ++j;
		}
		if (ss % (ss - f[ss - 1])) cout << 1 << '\n';
		else cout << ss / (ss-f[ss-1]) << '\n';
		cin >> s;
	}
}