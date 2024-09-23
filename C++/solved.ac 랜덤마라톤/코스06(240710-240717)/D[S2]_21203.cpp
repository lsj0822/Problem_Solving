#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long ans = 0;
pair<int, int> arr[200005];
bool xsort(pair<int, int> a, pair<int, int> b) {return a.first < b.first;}
bool ysort(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
	sort(&arr[0], &arr[n], xsort);
	long long tot = 0;
	for (int i = 1; i < n; i++) {
		tot += i * (arr[i].first - arr[i - 1].first);
		ans += tot;
	}
	sort(&arr[0], &arr[n], ysort);
	tot = 0;
	for (int i = 1; i < n; i++) {
		tot += i * (arr[i].second - arr[i-1].second);
		ans += tot;
	}
	cout << ans;
}