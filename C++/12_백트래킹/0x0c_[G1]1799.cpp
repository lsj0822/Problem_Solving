#include<iostream>

using namespace std;

bool vst_up[20], vst_dn[20];
int black = 0, white = 0, n = 0;
int board[11][11], vst[11][11];

void bt(int bs, bool color, int x, int y) {
	if (x == n) {
		if (!color) black = max(bs, black);
		else white = max(bs, white);
		return;
	}
	if (board[x][y] && !vst_up[x + y] && !vst_dn[x - y + n - 1]) { ;
		vst_up[x+y] = 1;
		vst_dn[x-y + n - 1] = 1;
		if (y + 2 >= n) {
			if (y % 2 == 0) bt(++bs, color, x + 1, 1);
			else bt(++bs, color, x + 1, 0);
		}
		else bt(++bs, color, x, y + 2);
		bs--;
		vst_up[x+y] = 0;
		vst_dn[x-y + n - 1] = 0;
 	}
	if (y + 2 >= n) {
		if (y % 2 == 0) bt(bs, color, x + 1, 1);
		else bt(bs, color, x + 1, 0);
	}
	else bt(bs, color, x, y + 2);
}


int main() {
	ios::sync_with_stdio(0);    
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	bt(0, 0, 0, 1);
	bt(0, 1, 0, 0);
	cout << black + white;
}