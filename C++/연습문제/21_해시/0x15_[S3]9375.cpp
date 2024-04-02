#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int t;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		int n, ans = 1;
		unordered_map<string, int> clothes;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			clothes[b]++;
		}
		for (auto c : clothes) {
			ans *= c.second+1;
		}
		cout << ans - 1 << '\n';
	}
}