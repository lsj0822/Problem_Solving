#include<bits/stdc++.h>

using namespace std;

void hanoi(int s, int e, int o, int n) {
	if (n == 1) {
		cout << s << " " << e << '\n';
		return;
	}
	hanoi(s, o, e, n - 1);
	cout << s << " " << e << '\n';
	hanoi(o, e, s, n - 1);
}

int main() {
	int n;
	cin >> n;
	cout << (1<<n) - 1 << '\n';
	hanoi(1, 3, 2, n);
}