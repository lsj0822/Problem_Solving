#include <iostream>
#include<algorithm>
using namespace std;
int n, arr[55], ans = 1;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(&arr[0], &arr[n]);
	for (int i = 0; i + 1 < n; i++) {
		int crit = arr[i] + arr[i + 1], j = i + 2;
		for (j= i + 2; j < n; j++) {
			if (arr[j] >= crit) break;
		}
		ans = max(ans, j - i);
	}
	cout << ans;
}