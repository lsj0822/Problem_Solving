#include<iostream>
#include<iomanip>
using namespace std;
double dp[20][200], ans[20][2];
double p[6] = { 1 / 16.,2 / 16.,6 / 16.,4 / 16.,2 / 16.,1 / 16. };
int score[6] = { -3,-1,0,1,2,3 };
int main() {
	for (int i = 0; i < 6; i++) dp[0][100 + score[i]] += p[i];
	for (int i = 1; i < 20; i++) {
		for (int j = 100 - i * 3; j <= 100 + i * 3; j++) {
			for (int k = 0; k < 6; k++) dp[i][j + score[k]] += dp[i-1][j] * p[k];
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 200; j++) {
			if (j == 100) continue;
			ans[i][j / 100] += dp[i][j];
		}
	}
	cout << "Round   A wins    B wins    Tie\n";
	for (int i = 0; i < 20; i++) {
		cout << fixed << setw(5) << i + 1;
		cout << setw(10) << setprecision(4) << ans[i][1]*100 << '%';
		cout << setw(9) << setprecision(4) << ans[i][0]*100 << '%';
		cout << setw(9) << setprecision(4) << dp[i][100]*100 << '%';
		cout << '\n';
	}
}