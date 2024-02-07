#include <bits/stdc++.h>
using namespace std;
int n, r[1005];
int main() {
	cin >> n;
	r[1] = 1; r[2] = 3;
	for (int i = 3; i <= n; i++) r[i] = (r[i - 1] + r[i - 2]*2) % 10007;
	cout << r[n];
}