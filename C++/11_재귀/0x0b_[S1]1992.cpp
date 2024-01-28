#include<iostream>
#include<string>
using namespace std;
int n;
string b[65];
void zip(int x, int y, int l) {
	char flag = b[x][y];
	for (int nx = x; nx < x + l; nx++) {
		for (int ny = y; ny < y + l; ny++) {
			if (b[nx][ny] != flag) {
				cout << '(';
				zip(x, y, l / 2);
				zip(x, y + l / 2, l / 2);
				zip(x + l / 2, y, l / 2);
				zip(x + l / 2, y + l / 2, l / 2);
				cout << ')';
				return;
			}
		}
	}
	cout << flag;
	return;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	zip(0, 0, n);
}