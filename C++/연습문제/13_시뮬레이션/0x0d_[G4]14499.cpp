#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, k, arr[25][25], dice[6];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int main() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (k--) {
		int dir;
		cin >> dir;
		int tmp_x = x + dx[dir - 1], tmp_y = y + dy[dir - 1];
		if (tmp_x < 0 || tmp_x >= n || tmp_y < 0 || tmp_y >= m) continue;
		if (arr[x][y] == 0) arr[x][y] = dice[5];
		else {
			dice[5] = arr[x][y];
			arr[x][y] = 0;
		}
		int tmp[6]; // 0 : top, 1 : west, 2 : north, 3 : east, 4 : south, 5 : bottom
		switch (dir) {
		case 1:
			tmp[0] = dice[1]; tmp[1] = dice[5];	tmp[2] = dice[2]; tmp[3] = dice[0]; tmp[4] = dice[4]; tmp[5] = dice[3];
			break;
		case 2:
			tmp[0] = dice[3]; tmp[1] = dice[0]; tmp[2] = dice[2]; tmp[3] = dice[5]; tmp[4] = dice[4]; tmp[5] = dice[1];
			break;
		case 3:
			tmp[0] = dice[4]; tmp[1] = dice[1]; tmp[2] = dice[0]; tmp[3] = dice[3]; tmp[4] = dice[5]; tmp[5] = dice[2];
			break;
		case 4:
			tmp[0] = dice[2]; tmp[1] = dice[1]; tmp[2] = dice[5]; tmp[3] = dice[3]; tmp[4] = dice[0]; tmp[5] = dice[4];
			break;
		}
		for (int i = 0; i < 6; i++) dice[i] = tmp[i];
		cout << dice[0] << '\n';
		x = tmp_x; y = tmp_y;
	}
}