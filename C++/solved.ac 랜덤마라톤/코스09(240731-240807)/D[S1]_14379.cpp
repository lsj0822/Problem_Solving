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

/*�̹����� Ǯ���� �� �������� S1�̾��µ� ����� S1 �ƴϴ�...
���Ʈ������ Ǯ�⿡�� ������ ����ġ�� ��ٷӰ�
�׷��ٰ� �̰��� �׷��� �̷����� Ǯ���� �׷����� ����Ŭ�� �Ǻ��ϴ� �����
��� ��忡�� �ʿ��ϴ�. ����� �ǹ� �ƴ�.*/