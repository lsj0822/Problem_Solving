#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t, n, f[15], circle[15], ans;
bool vst[15];
bool is_circle(int len) {
	for (int i = 0; i < len; i++) {
		if ((f[circle[i]] != circle[(i + 1) % len]) && (f[circle[i]] != circle[(i + len - 1) % len])) return false;
	}
	return true;
}
void BT(int dep) {
	if (ans == n) return;
	if (dep > ans) {
		if (is_circle(dep)) {
			ans = dep;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vst[i]) continue;
		if (dep >= 2 && (f[circle[dep - 1]] != i && circle[dep - 1] != f[i]
			&& f[circle[0]] != i && circle[0] != f[i] && f[circle[0]] != circle[1]
			&& circle[0] != f[circle[1]])) continue;
		vst[i] = 1;
		circle[dep] = i;
		BT(dep + 1);
		vst[i] = 0;
	}
}
int main() {
	cin >> t;
	for (int trial = 1; trial <= t; trial++) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> f[i];
		BT(0);
		cout << "Case #" << trial << ": " << ans << '\n';
	}
}

/*이문제는 풀었을 때 기준으로 S1이었는데 절대로 S1 아니다...
브루트포스로 풀기에는 조건이 지나치게 까다롭고
그렇다고 이것을 그래프 이론으로 풀려면 그래프의 사이클을 판별하는 기술은
적어도 골드에서 필요하다. 절대로 실버 아님.*/