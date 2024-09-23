#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	while (1) {
		map<string, int> m;
		int n, arr[5], max_popularity = -1, ans = 0;
		cin >> n;
		if (n == 0) return 0;
		for (int i = 0; i < n; i++) {
			string str;
			for (int j = 0; j < 5; j++) cin >> arr[j];
			sort(&arr[0], &arr[5]);
			for (int j = 0; j < 5; j++) str += to_string(arr[j]);
			m[str]++;
		}
		for (auto ls : m) max_popularity = max(max_popularity, ls.second);
		for (auto ls : m) {
			if (ls.second == max_popularity) ans += max_popularity;
		}
		cout << ans << '\n';
	}
}