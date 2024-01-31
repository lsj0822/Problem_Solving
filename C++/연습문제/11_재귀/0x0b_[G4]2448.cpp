#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int n;
char b[3200][6400];

void make_star(int x, int y, int size) {
	if (size == 3) {
		b[x][y] = '*';
		b[x + 1][y - 1] = '*';
		b[x + 1][y + 1] = '*';
		for (int i = 0; i < 5; i++) {
			b[x + 2][y - 2 + i] = '*';
		}
		return;
	}

	make_star(x, y, size / 2);
	make_star(x + size/2, y + size/2, size / 2);
	make_star(x + size/2, y - size/2, size / 2);
}

int main() {
	cin >> n;
	fill(&b[0][0], &b[n][n*2], ' ');
	make_star(0, n-1, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			cout << b[i][j];
		}
		cout << '\n';
	}
}