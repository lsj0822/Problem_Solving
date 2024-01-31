#include <bits/stdc++.h>

using namespace std;

int r = 0, st = 0;
string str;
stack<char> act;

int main() {
	cin >> str;
	for (auto c : str) {
		if (c == '(') st++;
		else {
			st--;
			if (act.top() == '(') {
				r += st;
			}
			else {
				r++;
			}
		}
		act.push(c);
	}
	cout << r;
}
