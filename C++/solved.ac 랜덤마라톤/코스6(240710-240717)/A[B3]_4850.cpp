#include<iostream>
using namespace std;
int main() {
	while (1) {
		int n, w, d, tot;
		cin >> n >> w >> d >> tot;
		if (cin.eof()) return 0;
		int res = (n * (n - 1) / 2 * w - tot) / d;
		cout << (res ? res : n) << '\n';
	}
}