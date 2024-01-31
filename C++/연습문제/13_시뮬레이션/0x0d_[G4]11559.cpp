#include <iostream>
#include <string>
#include <queue>
#include <utility>
#define X first
#define Y second

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int ans = 0;

using namespace std;
string container[13];

bool check_boom(int x, int y, char color) {
	queue<pair<int, int>> Q;
	int detect = 1, vst[12][6];
	fill(&vst[0][0], &vst[11][5], 0);
	Q.push({ x, y });
	vst[x][y] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
			if (vst[nx][ny] || container[nx][ny] != color) continue;
			vst[nx][ny] = 1;
			detect++;
			Q.push({ nx,ny });
		}
	}
	return detect / 4;
}
void change_boom(int x, int y, char color) {
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	container[x][y] = '*';
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
			if (container[nx][ny] != color) continue;
			container[nx][ny] = '*';
			Q.push({ nx,ny });
		}
	}
}

void make_boom(){
	ans++;
	while (true) {
		bool flag = true;
		for (int i = 0; i < 6; i++) {
			for (int j = 11; j > 0; j--) {
				if (container[j][i] == '*') {
					flag = false;
					swap(container[j][i], container[j - 1][i]);
				}
			}
		}

		for (int i = 0; i < 6; i++) {
			if (container[0][i] == '*') container[0][i] = '.';
		}
		if (flag) break;
	}
	
}
int main() {
	for (int i = 0; i < 12; i++) {
		cin >> container[i];
	}
	while (true) {
		bool flag = true;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (container[i][j] != '.' && container[i][j] != '*') {
					if (check_boom(i, j, container[i][j])) {
						change_boom(i, j, container[i][j]);
						flag = false;
					}
				}
			}
		}
		if (flag) break;
		else make_boom();
	}
	cout << ans;
}