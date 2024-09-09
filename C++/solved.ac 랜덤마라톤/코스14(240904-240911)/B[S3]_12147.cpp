#include<iostream>
using namespace std;
int trial;
int main() {
	cin >> trial;
	for (int t = 1; t <= trial; t++) {
		int r, c, w, res;
		cin >> r >> c >> w;
		res = r * (c / w) + w - 1 + (c%w!=0);
		cout << "Case #" << t << ": " << res << '\n';
	}
}