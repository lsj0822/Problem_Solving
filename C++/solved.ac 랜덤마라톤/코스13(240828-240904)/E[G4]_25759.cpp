#include<iostream>
using namespace std;
int n, dp[100005], arr[100005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 2; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			dp[i] = max(dp[i], dp[j] + (arr[i] - arr[j]) * (arr[i] - arr[j]));
			if (dp[i] - dp[j] > 10000) break;
			/*
			점화식이 최댓값을 갱신해나가는 구조인데,
			점화식에서 이전 인덱스에서의 차이가 특정 값( (100-1)^2 )보다 커지면 그 이전 인덱스에서는
			아무리 큰 값을 더해도 최댓값을 갱신할 수 없다. 그렇기에 99^2보다 커지는 지점에서 
			탐색을 종료한다.
			*/
		}
	}
	cout << dp[n];
}