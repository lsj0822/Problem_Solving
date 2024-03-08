#include <bits/stdc++.h>

using namespace std;
int a, b, prime[1000005];
int main() {
	prime[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		if (prime[i] == 1) continue;
		for (int j = 2; i * j <= 1000000; j++)	prime[i * j] = 1;
	}
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if (prime[i] == 0) cout << i << '\n';
	}
}