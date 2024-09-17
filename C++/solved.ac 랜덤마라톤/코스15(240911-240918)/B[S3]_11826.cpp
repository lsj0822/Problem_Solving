#include<iostream>
#include<vector>
using namespace std;
int h, w;
bool arr[55][55], test[55][55];
vector<int> ans;
bool candraw() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] != test[i][j]) return 0;
		}
	}
	return 1;
}
void make_line(int l) {
	if (l > 0) {
		for (int i = 0; i < h; i++) test[i][l-1] = 1;
	}
	else {
		for (int i = 0; i < w; i++) test[-l-1][i] = 1;
	}
}
bool complete_line(int n, int t) {
	switch (t) {
	case 0:
		for (int i = 0; i < w; i++) {
			if (!arr[n][i]) return 0;
		}
		break;
	case 1:
		for (int i = 0; i < h; i++) {
			if (!arr[i][n]) return 0;
		}
		break;
	}
	return 1;
}
bool white_cell() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j]) return 0;
		}
	}
	return 1;
}
int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		if (complete_line(i, 0)) ans.push_back(-(i + 1));
	}
	for (int i = 0; i < w; i++) {
		if (complete_line(i, 1)) ans.push_back(i + 1);
	}
	for (int v : ans) make_line(v);
	if (!candraw()) {
		cout << -1;
		return 0;
	}
	if (ans.size() == h + w) {
		cout << min(h, w) << '\n';
		if (h < w) {
			for (int i = 1; i <= h; i++) cout << -i << ' ';
		}
		else {
			for (int i = 1; i <= w; i++) cout << i << ' ';
		}
	}
	else {
		cout << ans.size() << '\n';
		for (int v : ans) cout << v << ' ';
	}
}