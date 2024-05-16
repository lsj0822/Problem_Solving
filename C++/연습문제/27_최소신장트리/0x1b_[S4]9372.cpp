#include<iostream>
using namespace std;
int t, n, m, a, b;
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) cin >> a >> b;
		cout << n - 1 << '\n';
	}
}