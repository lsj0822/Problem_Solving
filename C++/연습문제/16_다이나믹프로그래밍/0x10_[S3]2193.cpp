#include <bits/stdc++.h>

using namespace std;
int n;
long long arr[100][2];

int main() {
	cin >> n;
	arr[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i][1] = arr[i - 1][0];
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
	}
	cout << arr[n][0] + arr[n][1];
}