#include <iostream>
#include <set>

using namespace std;

int t;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		multiset<int> Q;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			char d;
			int n;
			cin >> d >> n;
			if (d == 'I') Q.insert(n);
			else {
				if (Q.empty()) continue;
				if (n == 1) Q.erase(prev(Q.end()));
				else Q.erase(Q.begin());
			}
		}
		if (Q.empty()) cout << "EMPTY\n";
		else cout << *prev(Q.end()) << ' ' << *Q.begin() << '\n';
	}
}