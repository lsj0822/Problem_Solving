#include<iostream>
using namespace std;
int n, k, b, ans = 1e7;
bool tl[100005];
int main(){
	cin >> n >> k >> b;
	while (b--) {
		int k;
		cin >> k;
		tl[k] = 1;
	}
	int cur = 0;
	for (int i = 1; i <= k; i++) cur += tl[i];
	for (int i = k + 1; i <= n; i++) {
		ans = min(ans, cur);
		cur += tl[i] - tl[i - k];
	}
	cout << min(ans,cur);
}