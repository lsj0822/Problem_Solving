#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#define X first
#define Y second
using namespace std;
pair<pair<double, double>, int> pos[8];
pair<double, double> ans = { 0,1e9 };
vector<pair<double, double>> A1, A2;
double res1 = 0, res2 = 0;
double calculating_area(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3) {
	double area = 1 / 2. * ((p1.X * p2.Y + p2.X * p3.Y + p3.X*p1.Y) - (p1.Y * p2.X + p2.Y * p3.X + p3.Y * p1.X));
	return abs(area);
}
int main() {
	for (int i = 0; i < 8; i+=2) cin >> pos[i].X.X >> pos[i].X.Y;
	for (int i = 1; i < 8; i+=2) {
		pos[i].X.X = (pos[i-1].X.X + pos[(i + 1) % 8].X.X) / 2;
		pos[i].X.Y = (pos[i-1].X.Y + pos[(i + 1) % 8].X.Y) / 2;
		pos[i].Y = 1;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 2 + pos[i].Y; j <= 6 - pos[i].Y; j++) {
			A1.clear(); A2.clear(); res1 = 0; res2 = 0;
			for (int k = 0; k <= j; k++) A1.push_back({pos[(i+k)%8].X.X,pos[(i+k)%8].X.Y});
			for (int k = j; k <= 8; k++) A2.push_back({pos[(i+k)%8].X.X,pos[(i+k)%8].X.Y});
			for (int k = 0; k < A1.size() - 2; k++) res1 += calculating_area(A1[0], A1[k + 1], A1[k + 2]);
			for (int k = 0; k < A2.size() - 2; k++) res2 += calculating_area(A2[0], A2[k + 1], A2[k + 2]);
			if (abs(res2 - res1) < abs(ans.X - ans.Y)) {
				ans.X = min(res1, res2);
				ans.Y = max(res1, res2);
			}
		}
	}
	cout << fixed << setprecision(3) << ans.X << ' ' << ans.Y;
}