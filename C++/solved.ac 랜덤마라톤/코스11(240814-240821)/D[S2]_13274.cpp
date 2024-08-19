#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
vector<ll> seq;
int n, k;
void query(int l, int r, ll x) {
	for (int i = l; i <= r; i++) {
		seq[i - 1] += x;
	}
	sort(seq.begin(), seq.end());
}
int main() {
	cin >> n >> k;
	while (n--) {
		ll num;
		cin >> num;
		seq.push_back(num);
	}
	sort(seq.begin(), seq.end());
	while (k--) {
		int l, r; ll x;
		cin >> l >> r >> x;
		query(l, r, x);
	}
	for (ll v : seq) cout << v << ' ';
}