#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, ans;
vector<ll> ls;
int digits = 0, added_num = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	string ntos = to_string(n);
	for (int i = 0; i < ntos.size(); i++) {
		if (ntos[i] == '0') continue;
		ls.push_back(stoi(ntos.substr(i, 1)));
	}
	while (1) {
		ans = n * pow(10,digits) + added_num;
		bool res = true;
		for (ll i : ls) {
			if (ans % i != 0) {
				res = false;
				break;
			}
		}
		if (res) break;
		added_num++;
		if (added_num >= pow(10, digits)) {
			digits++;
			added_num = 0;
		}
	}
	cout << ans;
}