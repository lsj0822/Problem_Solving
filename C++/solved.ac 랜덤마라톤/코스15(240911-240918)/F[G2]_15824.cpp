#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int DIV = 1e9 + 7;
int arr[300005], n;
long long ans = 0;
long long pow2(int p) {
	if (p == 0) return 1;
	if (p == 1) return 2;
	if (p % 2 == 1) return 2 * pow2(p / 2) % DIV * pow2(p / 2) % DIV;
	else return pow2(p / 2) % DIV * pow2(p / 2) % DIV;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(&arr[0], &arr[n]);
	for (int i = n-1; i >= 0; i--) {
		ans = (ans + arr[i] * ((pow2(i) - 1) - (pow2(n - 1 - i) - 1)))%DIV;
		if (ans < 0) ans += DIV;
	}
	cout << ans;
}