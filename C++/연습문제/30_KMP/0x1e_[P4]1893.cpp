#include<iostream>
#include<string>
#include<vector>
using namespace std;
int t, widx[50005];
vector<int> ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		ans.clear();
		string a, w, s;
		cin >> a >> w >> s;
		vector<int> f((int)w.size());
		int j = 0;
		for (int i = 1; i < (int)w.size(); i++) {
			while (j > 0 && w[i] != w[j]) j = f[j - 1];
			if (w[i] == w[j]) f[i] = ++j;
		}
		for (int i = 0; i < (int)w.size(); i++) widx[i] = a.find(w[i]);
		for (int i = 0; i < (int)a.size(); i++) {
			int cnt = 0; j = 0;
			for (int k = 0; k < (int)s.size(); k++) {
				while (j > 0 && s[k] != a[widx[j]]) j = f[j - 1];
				if (s[k] == a[widx[j]]) j++;
				if (j == (int)w.size()) {
					if (cnt >= 1) {
						cnt = 2;
						break;
					}
					cnt++;
					j = f[j - 1];
				}
			}
			if (cnt == 1) ans.push_back(i);
			for (int k = 0; k < (int)w.size(); k++) widx[k] = (widx[k] + 1) % ((int)a.size());
		}
		if (ans.size() == 0) cout << "no solution\n";
		else if (ans.size() == 1) cout << "unique: " << ans[0] << '\n';
		else {
			cout << "ambiguous: ";
			for (int v : ans) cout << v << ' ';
			cout << '\n';
		}
	}
}