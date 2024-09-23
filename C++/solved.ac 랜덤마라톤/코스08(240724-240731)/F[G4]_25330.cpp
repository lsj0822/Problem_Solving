#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;

int n, k, ans = 0;
pair<int, int> village[25];
bool vst[25];
void BT(int exp, int hp, int stack, int idx) {
	if (hp < 0) return;
	if (exp > ans) ans = exp;
	for (int i = idx + 1; i < n; i++) {
		if (vst[i]) continue;
		stack += village[i].X;
		vst[i] = 1;
		BT(exp + village[i].Y, hp - stack, stack, i);
		vst[i] = 0;
		stack -= village[i].X;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> village[i].X;
	for (int i = 0; i < n; i++) cin >> village[i].Y;
	sort(&village[0], &village[n]);
	BT(0, k, 0, -1);
	cout << ans;
}