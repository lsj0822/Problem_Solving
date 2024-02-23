#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int ans = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
pair<int, int> coor[7];
string str[5];
bool is_correct() {
	int dasom = 0, doyeon = 0, board[5][5], vst[5][5];
	fill(&board[0][0], &board[5][0], 0);
	fill(&vst[0][0], &vst[5][0], 0);
	for (int i = 0; i < 7; i++) {
		board[coor[i].X][coor[i].Y] = 1;
		if (str[coor[i].X][coor[i].Y] == 'Y') doyeon++;
		else dasom++;
	}
	if (doyeon > dasom) return false;
	int far = 0;
	queue<pair<int, int>> Q;
	for (int i = 0; i < 7; i++){
		auto pos = coor[i];
		if (vst[pos.X][pos.Y] == 0) {
			Q.push({ pos.X,pos.Y });
			vst[pos.X][pos.Y] = 1;
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vst[nx][ny] == 1) continue;
					if (board[nx][ny] == 1) {
						Q.push({ nx,ny });
						vst[nx][ny] = 1;
					}
				}
			}
			far++;
		}			
	}
	if (far == 1) return true;
	else return false;
}
void bt(int dep, int node) {
	if (dep == 7) {
		if (is_correct()) ans++;
		return;
	}
	for (int i = node+1; i < 25; i++) {
		coor[dep] = { i / 5, i % 5 };
		bt(dep + 1, i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
	}
	bt(0, -1);
	cout << ans;
}