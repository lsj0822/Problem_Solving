#include<iostream>
using namespace std;
const int MOD = 1e9 + 9;
int n;
long long ans = 1;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) ans = (2 * i - 1) * ans % MOD;
	cout << ans;
}