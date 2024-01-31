#include<bits/stdc++.h>

using namespace std;

int n;
int board[130][130], result[2];

void paper(int x, int y, int l) {
	int flag = board[x][y];
	if (l == 1) {
		result[flag]++;
		return;
	}
	for (int i = x; i < x + l; i++) {
		for (int j = y; j < y + l; j++) {
			if (board[i][j] != flag) {
				for (int nx : { x, x + l/2 }) {
					for (int ny : { y, y + l / 2 }) {
						paper(nx, ny, l / 2);
					}
				}
				return;
			}
		}
	}
	result[flag]++;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	paper(0, 0, n);
	for (auto r : result) {
		cout << r << '\n';
	}
}