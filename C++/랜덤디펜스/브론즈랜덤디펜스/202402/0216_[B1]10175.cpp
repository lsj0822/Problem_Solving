#include <bits/stdc++.h>

using namespace std;

int n, v[4];
string r, a;
string animal[4] = { "Coyote", "Bobcat", "Wolf", "Mountain Lion" };
bool d = false;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		fill(&v[0], &v[4], 0);
		int MX = 0, idx = 0;
		cin >> r >> a;
		for (char c : a) {
			for (int i = 0; i < 4; i++) {
					if (c == animal[i][0]) v[i] += (i + 1);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (v[i] > MX) {
				MX = v[i];
				idx = i;
				d = false;
			}
			else if (v[i] == MX) d = true;
		}
		cout << r << ": ";
		if (d) cout << "There is no dominant species\n";
		else cout << "The " << animal[idx] << " is the dominant species\n";
	}
}
