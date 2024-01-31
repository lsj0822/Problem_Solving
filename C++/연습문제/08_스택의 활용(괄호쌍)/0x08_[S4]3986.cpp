#include <bits/stdc++.h>

using namespace std;
int gw = 0, N;
string str;

int main() {
	cin >> N;
	while (N--) {
		cin >> str;
		stack<char> w;
		for (auto c : str) {
			if (w.empty()) w.push(c);
			else {
				if (w.top() == c) w.pop();
				else w.push(c);
			}
		}
		if (w.empty()) gw++;
	}
	cout << gw;
}