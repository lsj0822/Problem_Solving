#include<iostream>
using namespace std;
const int MOD = 1e9 + 7;
int n, m;
long long conqpow(int x, int p) {
	if (p == 0) return 1;
	if (p == 1) return x;
	if (p % 2 == 1) return x * conqpow(x, p / 2) %MOD * conqpow(x, p / 2) % MOD;
	else return conqpow(x, p / 2) % MOD * conqpow(x, p / 2) % MOD;
}

long long facto(int start, int end) {
	long long res = start;
	for (int i = start - 1; i > end; i--) {
		res = (res * i) % MOD;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	int nn = (1 << n);
	if (m > nn) {
		cout << 1;
		return 0;
	}
	if (m == 1) {
		cout << 0;
		return 0;
	}
	//1 - ((2^n)! / (2^n - m)!)/(2^n^m) = (2^nm - (2^n)! / (2^n - m))! ) / 2^nm
	// -> (2^nm - (2^n - m + 1 * ... * 2^n)) * (2^nm)^-1 = (all_pos - comple) * (all_pos)^(MOD-2) 
	long long all_possibility = conqpow(2,n * m)%MOD;
	long long complementary = facto(nn, nn-m)%MOD;
	cout << (all_possibility - complementary + MOD)%MOD * (conqpow(all_possibility, MOD - 2) % MOD) % MOD;
}