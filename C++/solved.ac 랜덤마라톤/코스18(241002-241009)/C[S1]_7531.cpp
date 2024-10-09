#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int dep, p, q, trial;
int dx[8] = { -2,-2,-1,1,2,2,1,-1 }, dy[8] = { -1,1,2,2,1,-1,-2,-2 };
string ans;
bool vst[30][30];

void BT(int depth, int x, int y, string pos) {
	if (depth == dep) {
		if (ans == "A1") ans = pos;
		else ans = min(ans, pos);
		return;
	}
	for (int dir = 0; dir < 8; dir++) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if (nx < 0 || nx >= p || ny < 0 || ny >= q) continue;
		if (vst[nx][ny]) continue;
		vst[nx][ny] = 1;
		char ypos = (ny + 'A');
		string xpos = to_string(nx + 1);
		BT(depth + 1, nx, ny, pos + ypos + xpos);
		vst[nx][ny] = 0;
	}
}

int main() {
	cin >> trial;
	for (int i = 1; i <= trial; i++) {
		fill(&vst[0][0], &vst[27][0], 0);
		cin >> p >> q;
		dep = p * q;
		ans = "A1";
		vst[0][0] = 1;
		BT(1, 0, 0, ans);
		cout << "Scenario #" << i << ":\n";
		if (ans == "A1" && dep != 1) cout << "impossible\n\n";
		else cout << ans << "\n\n";
	}
}
