#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, ans = 0;
int dx[4] = { 0,-1,0,1 }, dy[4] = { 1,0,-1,0 };
bool vst[105][105];
void find_route(vector<int>& vec, int nowgen, int targen) {
	if (targen == 0) return;
	vector<int> tmp;
	for (int v : vec) tmp.push_back(v);
	reverse(tmp.begin(), tmp.end());
	for (int v : tmp) vec.push_back((v + 1) % 4);
	if (nowgen == targen) return;
	find_route(vec, nowgen + 1, targen);
}
void dragon(int x, int y,int d,int g) {
	vector<int> v;
	v.push_back(d);
	find_route(v, 1, g);
	vst[x][y] = 1;
	for (int dir : v) {
		x = x + dx[dir], y = y + dy[dir];;
		if (x >= 0 && x <= 100 && y >= 0 && y <= 100) vst[x][y] = 1;
	}
}
bool isrect(int i, int j) {
	for (int x = i; x <= i + 1; x++) {
		for (int y = j; y <= j + 1; y++) {
			if (!vst[x][y]) return 0;
		}
	}
	return 1;
}
int main() {
	cin >> n;
	while (n--) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		dragon(x, y, d, g);
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (isrect(i, j)) ans++;
		}
	}
	cout << ans;
}