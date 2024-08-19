#include<iostream>
using namespace std;
int n;
long long blocks[6] = { 0, 0, 0, 0, 0, 1}, ans;
int main() {
	cin >> n;
	ans = n;
	for (int i = 2; i <= n; i++) {
		ans += blocks[(i - 1) % 6];
		if ((i - 1) % 6 == 0) {
			for (int j = 0; j < 6; j++) blocks[j]++;
		}
	}
	cout << ans;
}