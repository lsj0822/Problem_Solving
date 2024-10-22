#include<iostream>
using namespace std;
const int MOD = 998'244'353;
int t, n, k;

long long conqpow(int x, int p) {
	if (p == 0) return 1;
	if (p == 1) return x;
	if (p % 2 == 1) return (x * conqpow(x, p / 2) % MOD * conqpow(x, p / 2) % MOD) % MOD;
	else return (conqpow(x, p / 2) % MOD * conqpow(x, p / 2) % MOD) % MOD;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int res = 0;
		for (int i = 1; i <= k; i++) res = (res + conqpow(i+1, n))%MOD;
		cout << res << '\n';
	}
}