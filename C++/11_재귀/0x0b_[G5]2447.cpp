#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
char star[2200][2200];
int n;

void make_star(int x, int y, int size) {
	if (size == 3) {
		star[x + 1][y + 1] = ' ';
		return;
	}
	for (int i = x + size / 3; i < x + 2 * size / 3;i++) {
		for (int j = y + size / 3; j < y + 2 * size / 3;j++){
		star[i][j] = ' ';
		}
	}
	for (int nx = x; nx < x + size; nx += size / 3) {
		for (int ny = y; ny < y + size; ny += size / 3) {
			if (nx != x + size / 3 || ny != y + size / 3) {
				make_star(nx, ny, size / 3);
			}
		}
	}
}
int main() {
	cin >> n;
	fill(&star[0][0], &star[n + 1][n + 1], '*');
	make_star(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}
}