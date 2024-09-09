#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n, d, k, crit = 0, idx = 0;
pair<int, string> employee[10005];
int main() {
	cin >> n >> d >> k;
	for (int i = 0; i < n; i++) cin >> employee[i].second >> employee[i].first;
	sort(&employee[0], &employee[n], greater<>());
	while (idx < k && crit < d) {
		crit += employee[idx++].first;
	}
	if (idx == k && crit < d) cout << "impossible";
	else {
		cout << idx << '\n';
		for (int i = 0; i < idx; i++) cout << employee[i].second << ", YOU ARE FIRED!\n";
	}
}