#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string arr[11], start="", str;
unordered_map<string, int> freq;
int dx[8] = { 0,-1,-1,-1,0,1,1,1 }, dy[8] = { -1,-1,0,1,1,1,0,-1 };
int n, m, k;
void bt(string s, int x, int y) {
	freq[s]++;
	if (s.size() == 5) return;
	for (int dir = 0; dir < 8; dir++) {
		int nx = (n + x + dx[dir]) % n, ny = (m + y + dy[dir]) % m;
		bt(s + arr[nx][ny], nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bt(string(1,arr[i][j]), i, j);
		}
	}
	while (k--) {
		cin >> str;
		cout << freq[str] << '\n';
	}
}