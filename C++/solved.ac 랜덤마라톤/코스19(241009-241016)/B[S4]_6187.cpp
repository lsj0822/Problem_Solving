#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[20], c, ans = 0;
void cows(int dep, int weight) {
	if (dep == n) {
		if(weight <= c) ans = max(ans, weight);
		return;
	}
	for (int i : {0, 1}) {
		cows(dep + 1, weight + (i ? 0 : arr[dep]));
	}
}
int main() {
	cin >> c >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cows(0, 0);
	cout << ans;
}