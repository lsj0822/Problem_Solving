#include<iostream>
using namespace std;
bool vst[105];
int n, ans = 0;
int main() {
	cin >> n;
	while (n--) {
		int k; cin >> k;
		if (vst[k]) ans++;
		else vst[k] = 1;
	}
	cout << ans;
}