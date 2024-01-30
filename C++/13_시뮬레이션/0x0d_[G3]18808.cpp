#include<iostream>
#include<utility>

using namespace std;

int notebook[41][41];
int n, m, k, ans = 0;

void sticker_rotate(int container[][11], int* r, int* c) {
	int new_container[11][11];
	for (int i = 0; i < *r; i++) {
		for (int j = 0; j < *c; j++) {
			new_container[j][*r-i-1] = container[i][j];
		}
	}
	copy(&new_container[0][0], &new_container[10][10], &container[0][0]);
	swap(*r, *c);
}
bool detect_sticker(int container[][11], int x, int y, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (notebook[x + i][y + j] && container[i][j]) return false;
		}
	}
	return true;
}
bool input_sticker(int container[][11], int r, int c) {
	for (int i = 0; i <= n - r; i++) {
		for (int j = 0; j <= m - c; j++) {
			if (detect_sticker(container, i, j, r, c)) {
				for (int x = 0; x < r; x++) {
					for (int y = 0; y < c; y++) {
						if(container[x][y])	notebook[i + x][j + y] = container[x][y];
					}
				}
				return true;
			}
		}
	}
	return false;
}
int main() {
	cin >> n >> m >> k;
	while (k--) {
		int sticker[11][11];
		int r, c;
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
			}
		}
		for(int rot = 0; rot < 4; rot++) {
			if (input_sticker(sticker, r, c)) break;
			sticker_rotate(sticker, &r, &c);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += notebook[i][j];
		}
	}
	cout << ans;
}