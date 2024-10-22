#include<iostream>
#include<fstream>
using namespace std;
int arr[500][500], n, d;
bool sfind = false;
bool check(int x, int y, int num) {
	for (int i = 0; i < n; i++) {
		if (arr[i][y] == num) return 1;
		if (arr[x][i] == num) return 1;
	}
	int sx = x / d * d, sy = y / d * d;
	for (int i = sx; i < sx + d; i++) {
		for (int j = sy; j < sy + d; j++) {
			if (arr[i][j] == num) return 1;
		}
	}
	return 0;
}
void sudoku(int dep, ofstream& f) {
	if (dep > 240) cout << dep << ' ';
	if (sfind) return;
	if (dep == n * n) {
		sfind = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				f << arr[i][j] << ' ';
			}
			f << '\n';
		}
		return;
	}
	if (arr[dep / n][dep % n] != 0) {
		sudoku(dep + 1, f);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check(dep / n, dep % n, i)) continue;
		arr[dep / n][dep % n] = i;
		sudoku(dep + 1, f);
		arr[dep / n][dep % n] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ofstream file("result.txt");
	cin >> n;
	d = n;
	n = n*n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	sudoku(0, file);
}