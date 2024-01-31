#include <bits/stdc++.h>

using namespace std;
int N;
string str;

int main() {
	cin >> N;
	while (N--) {
		cin >> str;
		stack<char> ps;
		bool flag = true;
		for (auto c : str) {
			if (c == '(') ps.push(c);
			else {
				if (ps.empty()) {
					flag = false;
					break;
				}
				else {
					ps.pop();
				}
			}
		}
		if (!ps.empty()) flag = false;
		if (flag) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
}