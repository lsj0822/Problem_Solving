#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
double dp[105];
int n;
string comma(double f) {
	string str = to_string(f), ret = "";
	int deli = str.find('.');
	for (int i = 0; i < deli; i++) {
		ret += str[i];
		if (i != deli-1 && (deli - i-1) % 3 == 0) ret += ',';
	}
	for (int i = 0; i < 3; i++) ret += str[deli+i];
	return ret;
}
int main() {
	while (1) {
		double a, b, c;
		cin >> a;
		if (a == -1) return 0;
		cin >> b >> c >> n;
		dp[1] = a; dp[2] = b; dp[3] = c;
		for (int i = 4; i <= n; i++) {
			dp[i] = round(dp[i - 3] * dp[i - 2]/dp[i-1]*100)/100;
			if (dp[i] == 0) break;
		}
		cout << "Month " << n << " cost: $" << comma(dp[n]) << '\n';
	}
}