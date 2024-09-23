#include<iostream>
#include<algorithm>
using namespace std;
int ans = 0, cmd[3], n, k;
int main() {
	cin >> n;
	while (n--) {
		char c;
		cin >> c;
		switch (c) {
		case 'R':
			cmd[0]++;
			break;
		case 'U':
			cmd[1]++;
			break;
		case 'X':
			cmd[2]++;
			break;
		}
	}
	cin >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		int mv = min({ x - 1,y - 1,cmd[2] });
		x -= mv; y -= mv;
		if (x-1 <= cmd[0] && y-1 <= cmd[1]) ans++;
	}
	cout << ans;
}