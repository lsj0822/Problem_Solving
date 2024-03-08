#include <bits/stdc++.h>

using namespace std;

int n, two = 0, five = 0;
int cnttwo(int num) {
	int cnt = 0;
	while (1) {
		if (num % 2 != 0) return cnt;
		cnt++;
		num /= 2;
	}
}
int cntfive(int num) {
	int cnt = 0;
	while (1) {
		if (num % 5 != 0) return cnt;
		cnt++;
		num /= 5;
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		two += cnttwo(i);
		five += cntfive(i);
	}
	cout << min(two, five);
}