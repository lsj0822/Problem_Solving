#include<iostream>
#include<algorithm>
using namespace std;
int n, ans = 1e3;
bool A[6][11][11], B[11][11];
void reflection(bool A[][11]) {
	for (int i = 0; i < n; i++) {
		reverse(&A[i][0], &A[i][i+1]);
	}
}
void rotation(bool A[][11]) {
	bool tmp[11][11];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			tmp[i][j] = A[n - 1 - j][i - j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) A[i][j] = tmp[i][j];
	}
}
int tricmp(bool reflect, int rotate, bool A[][11], bool B[][11]) {
	int res = 0;
	if (reflect) reflection(A);
	for (int i = 0; i < rotate; i++) rotation(A);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			res += (A[i][j]^B[i][j]);
		}
	}
	return res;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> A[0][i][j];
			for (int k = 1; k < 6; k++) A[k][i][j] = A[0][i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> B[i][j];
		}
	}
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j < 3; j++) {
			ans = min(ans, tricmp(i, j, A[i*3+j], B));
		}
	}
	cout << ans;
}