#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#define X first
#define Y second
using namespace std;
const int NULL_BLOCK = 1000;
int n, m, board[25][25], tmp[25][25], score = 0;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int vst[25][25];
pair<pair<int, int>, pair<int, int>> MX;
queue<pair<int, int>> zeros;
vector<pair<int,int>> rm_ls[25][25];
void BFS(int x, int y) {
	rm_ls[x][y].push_back({ x,y });
	queue<pair<int, int>> Q;
	int type = board[x][y], cnt = 1;
	Q.push({ x,y }); vst[x][y] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || vst[nx][ny]) continue;
			if (board[nx][ny] == 0 || board[nx][ny] == type) {
				rm_ls[x][y].push_back({ nx,ny });
				Q.push({ nx, ny });
				cnt++;
				vst[nx][ny] = 1;
				if (board[nx][ny] == 0) zeros.push({ nx,ny });
			}
		}
	}
	int zsize = (int)zeros.size();
	if (cnt > MX.X.Y || (cnt == MX.X.Y && zsize > MX.X.X) ||
		(cnt == MX.X.Y && zsize == MX.X.X && x > MX.Y.X) ||
		(cnt == MX.X.Y && zsize == MX.X.X && x == MX.Y.X && y > MX.Y.Y)) MX = { {zsize,cnt},{x,y} };
	while (!zeros.empty()) {
		auto cur = zeros.front(); zeros.pop();
		vst[cur.X][cur.Y] = 0;
	}
}

void remove_block() {
	for (int i = 0; i < rm_ls[MX.Y.X][MX.Y.Y].size(); i++) {
		int x = rm_ls[MX.Y.X][MX.Y.Y][i].X, y = rm_ls[MX.Y.X][MX.Y.Y][i].Y;
		board[x][y] = NULL_BLOCK;
	}
}

void gravity() {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			int x = j;
			while (x > 0 && board[x][i] == NULL_BLOCK) x--;
			if (x != j && board[x][i] != -1) swap(board[x][i], board[j][i]);
		}
	}
}

void rotate() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = board[j][n - i - 1];
		}
	}
	memcpy(board, tmp, sizeof(tmp));
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	while (1) {
		fill(&vst[0][0], &vst[20][0], 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				rm_ls[i][j].clear();
			}
		}
		MX = { {0,0}, {0,0} };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] >= 1 && board[i][j] <= m) BFS(i, j);
			}
		}
		if (MX.X.Y <= 1) {
			cout << score;
			return 0;
		}
		score += MX.X.Y * MX.X.Y;
		remove_block();
		gravity();
		rotate();
		gravity();
	}
}