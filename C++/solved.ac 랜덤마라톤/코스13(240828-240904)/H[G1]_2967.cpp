#include<iostream>
#include<string>
#include<tuple>
using namespace std;
int r, c, cnt = 0, rx, ry, rs;
string arr[105];
bool vst[105][105];
bool new_space(int x, int y, int s) {
	bool res = false;
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			if (!vst[i][j]) {
				res = true;
				vst[i][j] = 1;
			}
		}
	}
	return res;
}
bool check(int x, int y, int s) {
	if (x + s >= r || y + s >= c) return false;
	for (int i = x; i <= x + s; i++) {
		for (int j = y; j <= y + s; j++) {
			if (arr[i][j] != 'x') return false;
		}
	}
	return true;
}
bool revcheck(int x, int y, int s) {
	if (x - s < 0 || y - s < 0) return false;
	for (int i = x; i >= x - s; i--) {
		for (int j = y; j >= y - s; j--) {
			if (arr[i][j] != 'x') return false;
		}
	}
	return true;
}
int revspace(int x, int y, int s) {
	if (revcheck(x, y, s)) return revspace(x, y, s + 1);
	else return s;
}
int space(int x, int y, int s) {
	if (check(x, y, s)) return space(x, y, s + 1);
	else return s;
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> arr[i];
	for (int i = 0; i < r; i++) {
		if (cnt == 1) break;
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'x') {
				int x = i + 1, y = j + 1, s = space(i, j, 1);
				bool tmp = new_space(i, j, s);
				cout << x << ' ' << y << ' ' << s << '\n';
				tie(rx, ry, rs) = tie(x, y, s);
				cnt++;
				break;
			}
		}
	}
	for (int i = r - 1; i >= 0; i--) {
		if (cnt == 2) break;
		for (int j = c - 1; j >= 0; j--) {
			if (arr[i][j] == 'x') {
				int s = revspace(i, j, 1);
				if (!new_space(i - s+1, j - s+1, s)) continue;
				cout << i-s+2 << ' ' << j-s+2 << ' ' << s;
				cnt++;
				break;
			}
		}
	}
	if (cnt == 1) cout << rx << ' ' << ry << ' ' << rs;
}