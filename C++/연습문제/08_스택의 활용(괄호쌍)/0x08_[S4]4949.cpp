#include <bits/stdc++.h>

using namespace std;
string str;

int main() {
	cin.ignore();
	while (true) {
		getline(cin, str);
		stack<char> s;
		bool flag = true;
		if (str == ".") {
			break;
		}

		for (auto c : str) {
			if (c == '(' or c == '[') {
				s.push(c);
			}
			else if (c == ')' or c == ']') {
				if (s.empty()) {
					flag = false;
					break;
				}
				else {
					if ((c == ')' and s.top() == '(') or (c == ']' and s.top() == '[')) {
						s.pop();
					}
					else {
						flag = false;
						break;
					}
				}
			}
		}
		if (!s.empty()) {
			flag = false;
		}
		if (flag) {
			cout << "yes";
		}
		else {
			cout << "no";
		}
		cout << '\n';
	}
}