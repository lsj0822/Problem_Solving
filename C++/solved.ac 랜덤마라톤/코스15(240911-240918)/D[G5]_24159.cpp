#include<iostream>
using namespace std;
int n, p, arr[10005];
long long ans = 0, mod[10005];
int expo(int x, int d) {
	if (d == 0) return 1;
	if (d == 1) return x;
	if (d % 2 == 1) return x * expo(x, d / 2)%p * expo(x, d / 2) % p;
	else return expo(x, d / 2)%p * expo(x, d / 2) % p;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> p >> n;
	for (int i = 0; i < p; i++) arr[i] = expo(i, n);
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			int res = (arr[i] + arr[j]) % p;
			mod[res]++;
		}
	}
	for (int i = 0; i < p; i++) ans += mod[arr[i]];
	cout << ans;
}