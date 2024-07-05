#include<iostream>
#include<vector>
using namespace std;
int n, cnt = 0;
char s[2000005], p[1000005];
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (i != n - 1) s[n + i] = s[i];
	}
	for (int i = 0; i < n; i++) cin >> p[i];
	vector<int> f(n); int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && p[i] != p[j]) j = f[j - 1];
		if (p[i] == p[j]) f[i] = ++j;
	}
	j = 0;
	for (int i = 0; i < 2 * n - 1; i++) {
		while (j > 0 && s[i] != p[j]) j = f[j - 1];
		if (s[i] == p[j]) j++;
		if (j == n) {
			cnt++;
			j = f[j - 1];
		}
	}
	int DIV = gcd(cnt, n);
	cout << cnt / DIV << '/' << n / DIV;
}