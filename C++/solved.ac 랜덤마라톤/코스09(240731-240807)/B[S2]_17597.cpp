#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int n;
double w, g, h, r;
double f(double i) {
	return sqrt(pow(g, 2) + pow(i, 2)) + sqrt(pow(h, 2) + pow(w - i, 2));
}
int main() {
	cin >> n;
	while (n--) {
		cin >> w >> g >> h >> r;
		double ans1 = sqrt(pow(w,2) + pow(max(g, h) - min(g, h),2)), ans2 = 1e9;
		g -= r; h -= r;
		double st = 0, en = w, lmid, rmid;
		while (en - st > 1e-6) {
			lmid =(st*2+en)/3, rmid=(st+en*2)/3;
			if (f(lmid) <= f(rmid)) en = rmid;
			else st = lmid;
		}
		ans2 = f(rmid);
		cout << fixed << setprecision(8) << ans1 << ' ' << ans2 << '\n';
	}
}