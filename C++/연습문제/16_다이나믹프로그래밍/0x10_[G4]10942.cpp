#include<bits/stdc++.h>
using namespace std;
int n, m, arr[2005];
bool is_palin[2005][2005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		is_palin[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int l = i, r = i;
		while(1) {
			l--; r++;
			if (l <= 0 || r > n) break;
			if (arr[l] == arr[r]) is_palin[l][r] = 1;
			else break;
		}
		l = i+1; r = i;
		while(1) {
			l--; r++;
			if (l <= 0 || r > n) break;
			if (arr[l] == arr[r]) is_palin[l][r] = 1;
			else break;
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << is_palin[a][b] << '\n';
	}
}