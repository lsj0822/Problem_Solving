#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;
int n, ans = 2;
int c[30][30];
int action[11];
void set2048(int ls[]) {
	int nc[30][30];
	copy(&c[0][0], &c[n][n], &nc[0][0]);
	for (int i = 0; i < 10; i++) {
		if (ls[i] == -1) break;
		//merge
		switch (ls[i]) {
		case 0: //up
			for (int x = 1; x < n; x++) {
				for (int y = 0; y < n; y++) {
					for (int d = 1; d <= x; d++) {
						if (nc[x - d][y] != 0 && nc[x - d][y] != nc[x][y]) break;
						if (nc[x - d][y] == nc[x][y] && nc[x][y] > 0) {
							nc[x - d][y] *= 2;
							nc[x][y] = -1;
						}
					}
				}
			}
			break;
		case 1: //left
			for (int x = 0; x < n; x++) {
				for (int y = 1; y < n; y++) {
					for (int d = 1; d <= y; d++) {
						if (nc[x][y - d] != 0 && nc[x][y - d] != nc[x][y]) break;
						if (nc[x][y - d] == nc[x][y] && nc[x][y] > 0) {
							nc[x][y - d] *= 2;
							nc[x][y] = -1;
						}
					}
				}
			}
			break;
		case 2: //down
			for (int x = n - 2; x >= 0; x--) {
				for (int y = 0; y < n; y++) {
					for (int d = 1; d < n - x; d++) {
						if (nc[x + d][y] != 0 && nc[x + d][y] != nc[x][y]) break;
						if (nc[x + d][y] == nc[x][y] && nc[x][y] > 0) {
							nc[x + d][y] *= 2;
							nc[x][y] = -1;
						}
					}
				}
			}
			break;
		case 3: //right
			for (int x = 0; x < n; x++) {
				for (int y = n - 2; y >= 0; y--) {
					for (int d = 1; d < n - y; d++) {
						if (nc[x][y + d] != 0 && nc[x][y + d] != nc[x][y]) break;
						if (nc[x][y + d] == nc[x][y] && nc[x][y] > 0) {
							nc[x][y + d] *= 2;
							nc[x][y] = -1;
						}
					}

				}
			}
			break;
		}

		//move
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (nc[x][y] == -1) nc[x][y] = 0;
			}
		}
		while (true) {
			bool flag = true;
			switch (ls[i]) {
			case 0:
				for (int x = 1; x < n; x++) {
					for (int y = 0; y < n; y++) {
						if (!nc[x - 1][y] && nc[x][y]) {
							swap(nc[x - 1][y], nc[x][y]);
							flag = false;
						}
					}
				}
				break;
			case 1:
				for (int x = 0; x < n; x++) {
					for (int y = 1; y < n; y++) {
						if (!nc[x][y - 1] && nc[x][y]) {
							swap(nc[x][y - 1], nc[x][y]);
							flag = false;
						}
					}
				}
				break;
			case 2:
				for (int x = n - 2; x >= 0; x--) {
					for (int y = 0; y < n; y++) {
						if (!nc[x + 1][y] && nc[x][y]) {
							swap(nc[x + 1][y], nc[x][y]);
							flag = false;
						}
					}
				}
				break;
			case 3:
				for (int x = 0; x < n; x++) {
					for (int y = n - 2; y >= 0; y--) {
						if (!nc[x][y + 1] && nc[x][y]) {
							swap(nc[x][y + 1], nc[x][y]);
							flag = false;
						}
					}
				}
				break;
			}
			if (flag) break;
		}

	//detect
	ans = max(*max_element(&nc[0][0], &nc[n][n]),ans);
	}
	return;
}

void bt(int dep) {
	set2048(action);
	if (dep == 10) return;
	for (int dir = 0; dir < 4; dir++) {
		action[dep] = dir;
		bt(dep + 1);
		action[dep] = -1;
	}
}
int main() {
	fill(&action[0], &action[10], -1);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}
	bt(0);
	cout << ans;
}