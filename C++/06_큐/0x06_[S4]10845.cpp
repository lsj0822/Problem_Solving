#include <bits/stdc++.h>

using namespace std;
int N;
queue<int> Q;
string str;
int main() {
	cin >> N;
	while (N--) {
		cin >> str;
		if (str == "push") {
			int k;
			cin >> k;
			Q.push(k);
		}
		else if (str == "front") {
			if (!Q.empty()) cout << Q.front();
			else cout << -1;
			cout << '\n';
		}
		else if (str == "back") {
			if (!Q.empty()) cout << Q.back();
			else cout << -1;
			cout << '\n';
		}
		else if (str == "size") {
			cout << Q.size() << '\n';
		}
		else if (str == "empty") {
			cout << static_cast<int>(Q.empty()) << '\n';
		}
		else if (str == "pop") {
			if (!Q.empty()) { 
				cout << Q.front();
				Q.pop();
			}
			else {
				cout << -1;
			}
			cout << '\n';
		}
	}
}