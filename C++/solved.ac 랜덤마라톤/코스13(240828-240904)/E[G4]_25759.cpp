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
			��ȭ���� �ִ��� �����س����� �����ε�,
			��ȭ�Ŀ��� ���� �ε��������� ���̰� Ư�� ��( (100-1)^2 )���� Ŀ���� �� ���� �ε���������
			�ƹ��� ū ���� ���ص� �ִ��� ������ �� ����. �׷��⿡ 99^2���� Ŀ���� �������� 
			Ž���� �����Ѵ�.
			*/
		}
	}
	cout << dp[n];
}