#include <bits/stdc++.h>

using namespace std;
int T, n;
string p, x;
deque<int> DQ;
int main() {
	cin >> T;
	while (T--) {
		DQ.clear();
		cin >> p >> n >> x;
		bool reverse = false, flag = true;
		int addn = 0;
		for (int i = 1; i < x.length(); i++) {
			if (x[i] == ',' or x[i] == ']') {
				if (addn) {
					DQ.push_back(addn);
				}
				addn = 0;
			}
			else {
				addn = addn * 10 + static_cast<int>(x[i] - '0');
			}
		}
		for (auto action : p) {
			if (action == 'D') {
				if (DQ.empty()) {
					flag = false;
					break;
				}
				else {
					if (reverse) DQ.pop_back();
					else DQ.pop_front();
				}
			}
			else if (action == 'R') {
				reverse = !reverse;
			}
		}

		if (flag) {
			if (DQ.empty()) {
				cout << "[]" << '\n';
			}
			else {
				cout << '[';
				while (DQ.size() != 1) {
					if (reverse) {
						cout << DQ.back() << ",";
						DQ.pop_back();
					}
					else {
						cout << DQ.front() << ",";
						DQ.pop_front();
					}
				}
				cout << DQ.front() << ']' << '\n';
			}
		}
		else {
			cout << "error" << '\n';
		}

	}
}