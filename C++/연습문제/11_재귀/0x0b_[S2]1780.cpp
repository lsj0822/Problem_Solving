#include<bits/stdc++.h>

using namespace std;

int n;
int board[2200][2200], result[3];

void paper(int x, int y, int l) {
	int flag = board[x][y];
	if (l == 1) {
		result[flag + 1]++;
		return;
	}
	for (int i = x; i < x+l; i++) {
		for (int j = y; j < y+l; j++) {
			if (board[i][j] != flag) {
				for (int nx = x; nx < x + l; nx += l / 3) {
					for (int ny = y; ny < y + l; ny += l / 3) {
						paper(nx, ny, l / 3);
					}
				}
				return;
			}
		}
	}
	
	result[flag + 1]++;
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