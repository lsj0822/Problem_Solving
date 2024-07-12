#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string board[4], MXstr;
const int MX = 2400005, ROOT = 1;
int w, b, unused = 2;
int nxt[MX][26], chk[MX];
int dx[8] = { 0,-1,-1,-1,0,1,1,1 }, dy[8] = { -1,-1,0,1,1,1,0,-1 }, score[9] = { 0,0,0,1,1,2,3,5,11 };
int ans = 0, cnt = 0;
bool vst[4][4], word_vst[MX];
int c2i(char c) {
	return c - 'A';
}
void bt(int x, int y, string s, int cur) {
	if (chk[cur] >= 1 && !word_vst[chk[cur]]) {;
		word_vst[chk[cur]] = 1;
		ans += score[s.size()];
		cnt++;
		if (MXstr.size() < s.size() || (MXstr.size() == s.size() && s < MXstr)) MXstr = s;
	}
	if (s.size() >= 8) return;
	for (int dir = 0; dir < 8; dir++) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		if (vst[nx][ny]) continue;
		char c = board[nx][ny];
		if (nxt[cur][c2i(c)] == -1) continue;
		vst[nx][ny] = 1;
		bt(nx, ny, s + c, nxt[cur][c2i(c)]);
		vst[nx][ny] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> w;
	fill(&chk[0], &chk[MX], 0);
	fill(&nxt[0][0], &nxt[MX-1][0], -1);
	for (int i = 1; i <= w; i++) {
		string str;
		cin >> str;
		int cur = ROOT;
		for (char c : str) {
			if (nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = unused++;
			cur = nxt[cur][c2i(c)];
		}
		chk[cur] = i;
	}
	cin >> b;
	while (b--) {
		fill(&word_vst[0], &word_vst[MX], 0);
		MXstr = "";
		ans = 0; cnt = 0;
		string s = "";
		for (int i = 0; i < 4; i++) cin >> board[i];
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				char c = board[x][y];
				if (nxt[ROOT][c2i(c)] == -1) continue;
				vst[x][y] = 1;
				bt(x, y, s+c, nxt[ROOT][c2i(c)]);
				vst[x][y] = 0;
			}
		}
		cout << ans << ' ' << MXstr << ' ' << cnt << '\n';
	}
}