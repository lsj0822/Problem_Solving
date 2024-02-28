#include <bits/stdc++.h>

using namespace std;

int n, arr[10];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "YES" << '\n' << arr[0] * 111;
}