#include<iostream>
#include<string>
using namespace std;
string sudoku[9];
bool vst[10][9][9];
bool errorcheck(char num, int x, int y) { //초기상태에 맞지 않는 입력을 판별하는 함수
	for (int i = 0; i < 9; i++) {
		if (i != x && sudoku[i][y] == sudoku[x][y]) return 1;
		if (i != y && sudoku[x][i] == sudoku[x][y]) return 1;
	}
	int xs = x / 3 * 3, ys = y / 3 * 3;
	for (int i = xs; i < xs + 3; i++) {
		for (int j = ys; j < ys + 3; j++) {
			if (i != x && j != y && sudoku[i][j] == sudoku[x][y]) return 1;
		}
	}
	return 0;
}
bool iserror() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] != '.') {
				if (errorcheck(sudoku[i][j], i, j)) return 1;
			}
		}
	}
	return 0;
}
void crossing(int num, int x, int y) { //각 숫자에 대해서 방문 처리를 해주는 함수
	for (int i = 0; i < 9; i++) {
		vst[num][x][i] = 1;
		vst[num][i][y] = 1;
	}
	int xs = x / 3 * 3, ys = y / 3 * 3;
	for (int i = xs; i < xs + 3; i++) {
		for (int j = ys; j < ys + 3; j++) {
			vst[num][i][j] = 1;
		}
	}
}
void init() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] != '.') {
				crossing(sudoku[i][j] - '0', i, j);
			}
		}
	}
}
bool crosshatching(int x, int y, int num) { //3*3 범위를 탐색하는 함수
	int xs = x / 3 * 3, ys = y / 3 * 3;
	for (int i = xs; i < xs + 3; i++) {
		for (int j = ys; j < ys + 3; j++) {
			if (i == x && j == y) {
				if (vst[num][i][j]) return 0;
			}
			else {
				if (!vst[num][i][j] && sudoku[i][j] == '.') return 0;
			}
		}
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 9; i++) cin >> sudoku[i];
	if (iserror()) {
		cout << "ERROR";
		return 0;
	}
	init();
	bool loop = true;
	while (loop) {
		loop = false;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				for (int n = 1; n <= 9; n++) {
					if (crosshatching(i, j, n)) {
						if (sudoku[i][j] != '.') {
							cout << "ERROR";
							return 0;
						}
						sudoku[i][j] = n + '0';
						crossing(n, i, j);
						loop = true;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < 9; i++) cout << sudoku[i] << '\n';
}