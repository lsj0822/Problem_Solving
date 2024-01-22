#include <bits/stdc++.h>

using namespace std;

int r = 0, m = 1;
stack<char> op;
string str;

int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			op.push(str[i]);
			m *= 2;
		}
		else if (str[i] == '[') {
			op.push(str[i]);
			m *= 3;
		}
		else {
			if (str[i] == ')')
			{
				if (op.empty() || op.top() != '(') {
					cout << 0;
					return 0;
				}
				else {
					if (str[i - 1] == '(') {
						r += m;
					}
					op.pop();
				}
				m /= 2;
			}
			if (str[i] == ']')
			{
				if (op.empty() || op.top() != '[') {
					cout << 0;
					return 0;
				}
				else {
					if (str[i - 1] == '[') {
						r += m;
					}
					op.pop();
				}
				m /= 3;
			}
		}
	}
	if (op.empty()) cout << r;
	else cout << 0;
}
