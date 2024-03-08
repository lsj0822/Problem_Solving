#include <bits/stdc++.h>

using namespace std;
int n;
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	cin >> n;
	while (n--) {
		long long a, b;
		cin >> a >> b;
		cout << a * b / gcd(a, b) << '\n';
	}
}