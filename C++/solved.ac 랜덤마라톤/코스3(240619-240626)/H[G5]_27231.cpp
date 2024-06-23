#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, cnt = 0, op[35];
vector<int> nv, num_list;
long long llpow(int n, int p) {
	long long res = 1;
	for (int i = 0; i < p; i++) res *= n;
	return res;
}
int calculating_number() {
	int res = 0, tmp = nv[0];
	for (int i = 1; i < static_cast<int>(nv.size()); i++) {
		if (op[i - 1] == 0) {
			if (nv[i - 1] == 0 && tmp == 0) return -1;
			else tmp = tmp * 10 + nv[i];
		}
		else {
			res += tmp;
			tmp = nv[i];
		}
	}
	res += tmp;
	return res;
}
void back_tracking(int depth) {
	if (depth == static_cast<int>(nv.size()) - 1) {
		num_list.push_back(calculating_number());
		return;
	}
	for (int i : {0, 1}) {
		op[depth] = i;
		back_tracking(depth + 1);
		op[depth] = -1;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		nv.clear(); num_list.clear(); cnt = 0;
		cin >> n;
		int cn = n;
		while (cn != 0) {
			nv.push_back(cn % 10);
			cn /= 10;
		}
		reverse(nv.begin(), nv.end());
		bool is_infinite = true;
		for (int v : nv) if (v >= 2) is_infinite = false;
		if (is_infinite) {
			cout << "Hello, BOJ 2023!\n";
			continue;
		}
		back_tracking(0);
		sort(num_list.begin(), num_list.end());
		for (int i = 1; i < 31; i++) {
			long long tmp = 0;
			for (int v : nv) tmp += llpow(v,i);
			if (tmp > n) break;
			cnt += (upper_bound(num_list.begin(), num_list.end(), tmp) - lower_bound(num_list.begin(), num_list.end(), tmp) >= 1) ?1:0;
		}
		cout << cnt << '\n';
	}
}