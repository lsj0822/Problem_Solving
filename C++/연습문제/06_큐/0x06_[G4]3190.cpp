#include <bits/stdc++.h>

using namespace std;
int N, K, L, t = 0, sx = 0, sy = 0, dir = 0;
int v[100][100] = {0}, a[100][100] = {0};
queue<pair<int, char>> action;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool escape = false;
queue<pair<int, int>> snake;

int main() {
	cin >> N >> K;
	while (K--) {
		int x, y;
		cin >> x >> y;
		a[x - 1][y - 1] = 1;
	}

	cin >> L;
	while (L--) {
		int at;
		char ad;
		cin >> at >> ad;
		action.push(make_pair(at, ad));
	}

	snake.push(make_pair(0, 0));
	v[0][0] = 1;
	while (!escape) {
		int nx, ny, rx, ry;
		rx = snake.back().first;
		ry = snake.back().second;
		nx = rx + dx[dir];
		ny = ry + dy[dir];
		t++;
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || v[ny][nx] ) {
			escape = true;
			continue;
		}
		if (a[ny][nx]) {
			a[ny][nx] = 0;
		}
		else {
			v[snake.front().second][snake.front().first] = 0;
			snake.pop();
		}
		snake.push(make_pair(nx, ny));
		v[ny][nx] = 1;

		if (!action.empty()) {
			if (action.front().first == t) {
				if (action.front().second == 'D') {
					dir = (dir + 1) % 4;
				}
				else {
					dir = (dir + 3) % 4;
				}
				action.pop();
			}
		}
	}
	cout << t;
}