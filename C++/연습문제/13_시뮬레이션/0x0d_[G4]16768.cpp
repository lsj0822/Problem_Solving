#include <iostream>
#include <string>
#include <queue>
#include <utility>
#define X first
#define Y second

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n,k;
using namespace std;
string container[105];

bool check_boom(int x, int y, char type) {
	queue<pair<int, int>> Q;
	int detect = 1, vst[105][10];
	fill(&vst[0][0], &vst[n][10], 0);
	Q.push({ x, y });
	vst[x][y] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= 10) continue;
			if (vst[nx][ny] || container[nx][ny] != type) continue;
			vst[nx][ny] = 1;
			detect++;
			Q.push({ nx,ny });
		}
	}
	return detect / k;
}
void change_boom(int x, int y, char type) {
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	container[x][y] = '*';
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= 10) continue;
			if (container[nx][ny] != type) continue;
			container[nx][ny] = '*';
			Q.push({ nx,ny });
		}
	}
}

void make_boom(){
	while (true) {
		bool flag = true;
		for (int i = 0; i < 10; i++) {
			for (int j = n-1; j > 0; j--) {
				if (container[j][i] == '*') {
					flag = false;
					swap(container[j][i], container[j - 1][i]);
				}
			}
		}

		for (int i = 0; i < 10; i++) {
			if (container[0][i] == '*') container[0][i] = '0';
		}
		if (flag) break;
	}
	
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> container[i];
	}
	while (true) {
		bool flag = true;
		for (int i = n-1; i >= 0; i--) {
			for (int j = 0; j < 10; j++) {
				if (container[i][j] != '*' && container[i][j] != '0') {
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cout << container[i][j];
		}
		cout << '\n';
	}
}