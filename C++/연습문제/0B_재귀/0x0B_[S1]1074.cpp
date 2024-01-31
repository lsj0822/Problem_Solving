#include<bits/stdc++.h>

using ll = long long;
using namespace std;
int n, r, c;

ll Z(int x, int y, int n) {
	if (n == 1) return (r - x) * 2 + (c - y);
	int multiple = (1 << (n - 1));
	int addx = ((r-x) / multiple) * multiple;
	int addy = ((c-y) / multiple) * multiple;
	return addx * multiple * 2 + addy * multiple + Z(x + addx, y + addy, n - 1);
}

int main() {
	cin >> n >> r >> c;
	cout << Z(0, 0, n);
}