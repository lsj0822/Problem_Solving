#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int x, y, year, glacier[305][305], vst[305][305], melt[305][305];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

bool check_boundary(int a, int b) {
	return (a < 0 || a >= x || b < 0 || b >= y);
}

void glacier_melt() {
	fill(&melt[0][0], &melt[301][301], 0);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			int tmp = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir], ny = j + dy[dir];
				if (check_boundary(nx,ny) || glacier[nx][ny]) continue;
				tmp++;
			}
			melt[i][j] = tmp;
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			glacier[i][j] = max(0, glacier[i][j] - melt[i][j]);
		}
	}
}

int glacier_search() {
	int res = 0;
	fill(&vst[0][0], &vst[301][301], 0);
	queue<pair<int,int>> Q;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (glacier[i][j] && !vst[i][j]) {
				vst[i][j] = 1;
				Q.push({ i,j });
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
						if (check_boundary(nx, ny) || vst[nx][ny] || !glacier[nx][ny]) continue;
						vst[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
				res++;
			}
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> glacier[i][j];
		}
	}
	while (true) {
		glacier_melt();
		year++;
		int glacier_count = glacier_search();
		if (glacier_count >= 2) {
			cout << year;
			return 0;
		}
		else if (!glacier_count) {
			cout << 0;
			return 0;
		}
	}
}