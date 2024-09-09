#include<iostream>
using namespace std;
bool arr[10][10];
int ans = 1e4;
bool is_rect(int x, int y, int s) {
	if (x + s >= 11 || y + s >= 11) return 0;
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			if (!arr[i][j]) return 0;
		}
	}
	return 1;
}
bool taskdone() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j]) return 0;
		}
	}
	return 1;
}
void make_rect(int x, int y, int s, bool t) {
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			arr[i][j] = t;
		}
	}
}

void back_tracking(int dep, int x, int y, int cnt[5]) {
	if (taskdone()) {
		ans = min(ans, dep);
		return;
	}
	if (dep >= ans) return;
	for (int i = x; i < 10; i++) {
		for (int j = (i==x?y:0); j < 10; j++) {
			if (arr[i][j]) {
				for (int s = 5; s >= 1; s--) {
					if (is_rect(i, j, s) && cnt[s-1] > 0) {
						cnt[s - 1]--;
						make_rect(i, j, s, 0);
						back_tracking(dep + 1, i, j, cnt);
						cnt[s - 1]++;
						make_rect(i, j, s, 1);
					}
				}
				return;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}
	int initcnt[5] = { 5,5,5,5,5 };
	back_tracking(0, 0, 0, initcnt);
	if (ans == 1e4) ans = -1;
	cout << ans;
}