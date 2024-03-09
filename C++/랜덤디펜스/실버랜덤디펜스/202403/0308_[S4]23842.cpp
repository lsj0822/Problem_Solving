#include <bits/stdc++.h>

using namespace std;
int match[10] = { 6,2,5,5,4,5,6,3,7,6 }, n;
int main() {
	cin >> n;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (i + j >= 100) continue;
			if (match[i / 10] + match[i % 10] + match[j / 10] + match[j % 10] + match[(i + j) / 10] + match[(i + j) % 10] == n - 4) {
				cout << setfill('0') << setw(2) << i << "+" << setw(2) << j << "=" << setw(2) << i + j;
				return 0;
			}
		}
	}
	cout << "impossible";
}