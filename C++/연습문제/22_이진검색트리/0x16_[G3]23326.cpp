#include <iostream>
#include <set>

using namespace std;

int N, Q, pos = 1;
set<int> MN;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		int k; cin >> k;
		if (k) MN.insert(i);
	}
	for (int i = 0; i < Q; i++) {
		int query;
		cin >> query;
		switch (query) {
		case 1:
			int k;
			cin >> k;
			if (MN.find(k) != MN.end()) MN.erase(k);
			else MN.insert(k);
			break;
		case 2:
			cin >> k;
			pos = (pos - 1 + k) % N + 1;
			break;
		case 3:
			if (MN.empty()) cout << -1 << '\n';
			else {
				if (MN.lower_bound(pos) != MN.end()) cout << *MN.lower_bound(pos) - pos << '\n';
				else cout << *MN.begin() + N - pos << '\n';
			}
		}
	}
}