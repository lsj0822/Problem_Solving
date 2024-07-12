#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int t;
int main() {
	cin >> t;
	for (int trial = 1; trial <= t; trial++) {
		int c, d, n;
		string cstr[36], dstr[28], nstr;
		stack<char> ans;
		vector<char> ansvec;
		cin >> c;
		for (int i = 0; i < c; i++) cin >> cstr[i];
		cin >> d;
		for (int i = 0; i < d; i++) cin >> dstr[i];
		cin >> n >> nstr;
		for (int i = 0; i < n; i++) {
			vector<char> tmp;
			char cur = nstr[i];
			if (ans.size() == 0) ans.push(cur);
			else {
				bool ss = false;
				for (int j = 0; j < c; j++) {
					if ((ans.top() == cstr[j][0] && cur == cstr[j][1]) ||
						(ans.top() == cstr[j][1] && cur == cstr[j][0])) {
						ans.pop();
						ans.push(cstr[j][2]);
						ss = true;
						break;
					}
				}
				if (ss) continue;
				bool rm = false;
				while (!ans.empty() && !rm) {
					for (int j = 0; j < d; j++) {
						if ((ans.top() == dstr[j][0] && cur == dstr[j][1]) ||
							(ans.top() == dstr[j][1] && cur == dstr[j][0])) {
							while(!ans.empty()) ans.pop();
							rm = true;
							break;
						}
					}
					if (!rm) {
						tmp.push_back(ans.top());
						ans.pop();
					}
				}
				if (!rm) {
					reverse(tmp.begin(), tmp.end());
					for (char s : tmp) ans.push(s);
					ans.push(cur);
				}
			}
		}
		cout << "Case #" << trial << ": [";
		while (!ans.empty()) {
			ansvec.push_back(ans.top());
			ans.pop();
		}
		reverse(ansvec.begin(), ansvec.end());
		for (int j = 0; j < ansvec.size(); j++) {
			cout << ansvec[j];
			if (j != ansvec.size() - 1) cout << ", ";
		}
		cout << "]\n";
	}
}