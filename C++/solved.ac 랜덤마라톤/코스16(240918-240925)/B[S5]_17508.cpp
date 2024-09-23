#include<iostream>
#include<string>
using namespace std;
int n, m, ans = 0;
string arr[505];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (n % 2 == 1 && m % 2 == 1 && arr[n / 2][m / 2] != '8') {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char crit = arr[i][j], oppo = arr[n-1-i][m-1-j];
			if (crit == '6' || crit == '9') {
				if (oppo != '6' && oppo != '9') {
					cout << -1;
					return 0;
				}
				ans += (crit == oppo);
			}
			else {
				if (crit != oppo) {
					cout << -1;
					return 0;
				}
				ans += (crit == '7');
			}
		}
	}
	cout << ans/2;
}