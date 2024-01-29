#include<iostream>;
#define X first
#define Y second

using namespace std;

int n, r = 0;
pair<int, int> egg[10];

void bt(int idx) {
	if (idx == n) {
		int be = 0;
		for (int i = 0; i < n; i++) {
			if (egg[i].X <= 0) be++;
		}
		r = max(r, be);
		return;
	}
	if (egg[idx].X <= 0) bt(idx + 1);
	else {
		bool egg_empty = true;
		for (int i = 0; i < n; i++) {
			if (i == idx || egg[i].X <= 0) continue;
			egg[idx].X -= egg[i].Y;
			egg[i].X -= egg[idx].Y;
			egg_empty = false;
			bt(idx + 1);
			egg[idx].X += egg[i].Y;
			egg[i].X += egg[idx].Y;
		}
		if (egg_empty) bt(n);
	}
	
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, w;
		cin >> s >> w;
		egg[i] = { s,w };
	}
	bt(0);
	cout << r;
}