#include<iostream>
#include<tuple>
#include <string.h>
using namespace std;
int n, m, cow[1005], temp[1005], ans = 1e8;
tuple<int, int, int, int> air[15];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int s, t, c;
		cin >> s >> t >> c;
		for (int j = s; j <= t; j++) cow[j] = c;
	}
	for (int i = 0; i < m; i++) {
		int a, b, p, m;
		cin >> a >> b >> p >> m;
		air[i] = make_tuple( a,b,p,m );
	}
	for (int i = 1; i < (1 << m); i++) {
		int tmp = 0, seed = i;
		bool res = true;
		memset(temp, 0, sizeof(temp));
		for (int j = 0; j < m; j++) {
			if (seed % 2 == 1) {
				int a, b, p, m;
				tie(a, b, p, m) = air[j];
				for (int k = a; k <= b; k++) temp[k] += p;
				tmp += m;
			}
			seed /= 2;
		}
		for (int j = 0; j <= 1000; j++) {
			if (cow[j] != 0 && cow[j] > temp[j]) {
				res = false;
				break;
			}
		}
		if (res) ans = min(ans, tmp);
	}
	cout << ans;
}