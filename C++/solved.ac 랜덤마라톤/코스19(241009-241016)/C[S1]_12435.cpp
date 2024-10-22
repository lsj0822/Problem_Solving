#include<iostream>
using namespace std;
const int SIZE = 1e6 + 5;
int divcnt[SIZE], minval[SIZE];
int n, m, trial, cnt;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i <= 500000; i++) {
		for (int j = 2; i * j <= 1000000; j++) {
			divcnt[i * j]++;
			if (minval[i * j] == 0) minval[i*j] = i;
		}
	}
	cin >> trial;
	for (int t = 1; t <= trial; t++) {
		cin >> n >> m;
		cnt = 0;
		for (int i = n - 1; i >= m; i--) {
			cnt += (divcnt[n] == divcnt[i] && minval[i] >= m);
		}
		cout << "Case #" << t << ": " << cnt << '\n';
	}
}