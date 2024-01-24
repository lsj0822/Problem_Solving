#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m, r = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[602];
int vst[602][602];

int main() {
	cin >> n >> m;
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		board[i] = str;
		for (int j = 0; j < m; j++) {
			if (str[j] == 'I') {
				Q.push({ i, j });
				vst[i][j] = 1;
			}
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vst[nx][ny] || board[nx][ny] == 'X') continue;
			if (board[nx][ny] == 'P') r++;
			vst[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
	if (r) cout << r;
	else cout << "TT";
}