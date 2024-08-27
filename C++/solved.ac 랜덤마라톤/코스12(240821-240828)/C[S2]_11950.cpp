#include<iostream>
#include<string>
using namespace std;
string flag[55];
int n, m, ans = 1e5, tmp;
char cmp;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> flag[i];
	for (int b = 1; b < n; b++) {
		for (int r = b + 1; r < n; r++) {
			tmp = 0;
			cmp = 'W';
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (flag[i][j] != cmp) tmp++;
				}
				if (i == b-1) cmp = 'B';
				if (i == r-1) cmp = 'R';
			}
			ans = min(ans, tmp);
		}
	}
	cout << ans;
}