#include<iostream>
#define ll long long
using namespace std;
ll x, y turn_tot, tot, crit = 1;
int ans = 0;
int main() {
	cin >> x >> y;
	tot = a + b;
	while (1) {
		turn_tot = crit * (crit + 1) / 2;
		if (turn_tot > tot) {
			cout << -1;
			return 0;
		}
		else if (turn_tot == tot) break;
		crit++;
	}
	while (a > 0) {
		a -= crit--;
		ans++;
	}
	cout << ans;
}