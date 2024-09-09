#include<iostream>
#include<string>
using namespace std;
const int MX = 20;
string board[4];
bool arr[4][4];
int ans = MX, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
void fliping(int seed) {
	bool tmp[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp[i][j] = arr[i][j];
		}
	}
	int ones = 0, asum = 0;
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4; k++) {
			if (seed % 2 == 1) {
				ones++;
				tmp[j][k] = 1 - tmp[j][k];
				for (int dir = 0; dir < 4; dir++) {
					int nx = j + dx[dir], ny = k + dy[dir];
					if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
					tmp[nx][ny] = 1 - tmp[nx][ny];
				}
			}
			seed /= 2;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			asum += tmp[i][j];
		}
	}
	if (asum == 0 || asum == 16) ans = min(ans, ones);
}
int main() {
	for (int i = 0; i < 4; i++) cin >> board[i];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = (board[i][j] == 'b');
		}
	}
	for (int i = 0; i < (1 << 16); i++) {
		fliping(i);
	}
	cout << ((ans==MX)?"Impossible":to_string(ans));
}