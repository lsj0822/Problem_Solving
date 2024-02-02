#include<iostream>
#include<string>

using namespace std;

string gear[4];
int cur[4], k, ans = 0;
int turn[4];
void detect_left(int gn, int dir) {
	if (gn - 1 >= 0 ) {
		if (gear[gn - 1][(cur[gn - 1] + 2) % 8] != gear[gn][(cur[gn] + 6) % 8]) {
			turn[gn - 1] = -dir;
			detect_left(gn - 1, -dir);
		}
	}
}
void detect_right(int gn, int dir) {
	if (gn + 1 < 4) {
		if ((gear[gn + 1][(cur[gn + 1] + 6) % 8]) != gear[gn][(cur[gn] + 2) % 8]){
			turn[gn + 1] = -dir;
			detect_right(gn + 1, -dir);
		}
	}
}
int main() {
	for (int i = 0; i < 4; i++) {
		cin >> gear[i];
	}
	cin >> k;
	while (k--) {
		fill(&turn[0], &turn[4], 0);
		int gn, dir;
		cin >> gn >> dir;
		turn[gn-1] = dir;
		detect_left(gn-1, dir);
		detect_right(gn-1, dir);
		for (int i = 0; i < 4; i++) {
			cur[i] = (cur[i] - turn[i] + 8) % 8;
		}
	}
	for (int i = 0; i < 4; i++) {
		ans += (static_cast<int>(gear[i][cur[i]] - '0')) << i;
	}
	cout << ans;
}