#include<iostream>
#include<vector>
using namespace std;
const int ang = 360000;
int org[ang*2+1], cmp[ang], n;
bool res = false;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		org[k] = 1; org[ang + k] = 1;
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		cmp[k] = 1;
	}
	vector<int> f(ang); int j = 0;
	for (int i = 1; i < ang; i++) {
		while (j > 0 && cmp[i] != cmp[j]) j = f[j - 1];
		if (cmp[i] == cmp[j]) f[i] = ++j;
	}
	j = 0;
	for (int i = 0; i < ang*2; i++) {
		while (j > 0 && org[i] != cmp[j]) j = f[j - 1];
		if (org[i] == cmp[j]) j++;
		if (j == ang) {
			res = true;
			break;
		}
	}
	if (!res) cout << "im";
	cout << "possible";
}