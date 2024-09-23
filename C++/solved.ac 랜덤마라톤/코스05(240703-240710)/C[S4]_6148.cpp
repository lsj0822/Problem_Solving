#include<iostream>
using namespace std;
int n, b, h[25], ans = 1e9;
void back_tracking(int depth, int height) {
	if (depth == n) {
		if(height >= b) ans = min(ans, height - b);
		return;
	}
	for (int i : {0, 1}) {
		if (i) back_tracking(depth + 1, height + h[depth]);
		else back_tracking(depth + 1, height);
	}
}
int main() {
	cin >> n >> b;
	for (int i = 0; i < n; i++) cin >> h[i];
	back_tracking(0, 0);
	cout << ans;
}