#include<iostream>

using namespace std;
int k;
int s[15], v[15], b[6];
void bt(int dep, int start) {
	if (dep == 6) {
		for (int i = 0; i < 6; i++) {
			cout << b[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < k; i++) {
		if (!v[i]) {
			b[dep] = s[i];
			v[i] = 1;
			bt(dep + 1, i+1);
			v[i] = 0;
		}
	}
}

int main() {
	while (true) {
		int v[15] = { 0 }, b[6] = { 0 };
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}
		bt(0, 0);
		cout << '\n';
	}
}