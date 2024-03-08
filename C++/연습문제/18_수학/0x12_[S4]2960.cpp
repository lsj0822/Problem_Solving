#include <bits/stdc++.h>

using namespace std;

int n,k,che[1005],idx=0;
int main() {
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		if (che[i] == 1) continue;
		for (int j = 1; j * i <= n; j++) {
			if (che[i * j] == 1) continue;
			che[i * j] = 1;
			idx++;
			if (idx == k) {
				cout << i * j;
				return 0;
			}
		}
	}
}