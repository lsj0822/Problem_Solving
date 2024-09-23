#include<iostream>
using namespace std;
long long n, m;
long long f(long long x) {
	long long res = 0;
	for (long long i = 1; i <= x; i *= 2) {
		res += i * (((x - i) / (i * 2)) + 1);
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	cout << f(m) - f(n - 1);
}