#include<iostream>
using namespace std;
int get_clock(int x1, int x2, int x3, int x4) {
	int num[4] = {x1,x2,x3,x4}, res = 10000;
	for (int i = 0; i < 4; i++) {
		int tmp = 0;
		for (int j = 0; j < 4; j++) tmp = tmp * 10 + num[(i + j) % 4];
		res = min(res, tmp);
	}
	return res;
}
int main() {
	int ans = 0, clock, num[4], vst[10000] = { 0, };
	for (int i = 0; i < 4; i++) cin >> num[i];
	clock = get_clock(num[0], num[1], num[2], num[3]);
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				for (int l = 1; l <= 9; l++) {
					int mn = get_clock(i, j, k, l);
					if (vst[mn] == 0) vst[mn] = 1;
				}
			}
		}
	}
	for (int i = 1111; i <= clock; i++) ans += vst[i];
	cout << ans;
}