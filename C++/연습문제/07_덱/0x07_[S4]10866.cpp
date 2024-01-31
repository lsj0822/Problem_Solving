#include <bits/stdc++.h>

using namespace std;

int n;
deque<int> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str == "push_front") {
			int inp;
			cin >> inp;
			dq.push_front(inp);
		}
		else if (str == "push_back") {
			int inp;
			cin >> inp;
			dq.push_back(inp);
		}
		else if (str == "size") cout << dq.size() << '\n';
		else if (str == "empty") cout << static_cast<int>(dq.empty()) << '\n';
		else {
			if (dq.empty()) cout << -1;
			else {
				if (str == "front") cout << dq.front();
				else if (str == "back") cout << dq.back();
				else if (str == "pop_front") {
					cout << dq.front();
					dq.pop_front();
				}
				else if (str == "pop_back") {
					cout << dq.back();
					dq.pop_back();
				}
			}
			cout << '\n';
		}
	}
}