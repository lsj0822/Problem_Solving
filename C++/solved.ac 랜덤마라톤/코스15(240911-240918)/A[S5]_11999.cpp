#include<iostream>
using namespace std;
int x, y, m, ans = 0;
int main() {
	cin >> x >> y >> m;
	for (int i = 0; i < m / x + 1; i++) {
		for (int j = 0; j < m / y + 1; j++) {
			int tmp = i * x + j * y;
			if (tmp <= m && ans <= tmp) ans = tmp;
		}
	}
	cout << ans;
}