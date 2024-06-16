#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main() {
	while (1) {
		int k;
		cin >> k;
		if (k == 0) return 0;
		vector<int> res;
		int ans[10] = { 0, };
		res.push_back(1);
		for (int i = 2; i <= k; i++) {
			int left = 0;
			for (int v = 0; v < res.size(); v++) {
				int cal = res[v] * i;
				res[v] = (cal+left) % 10;
				left = (cal + left) / 10;
			}
			while (left != 0) {
				res.push_back(left % 10);
				left /= 10;
			}
		}
		for (int v : res) ans[v]++;
		cout << k << "! --\n";
		for (int i = 0; i < 5; i++) cout << "   (" << i << ")" << setw(5) << ans[i] << " ";
		cout << '\n';
		for (int i = 5; i < 10; i++) cout << "   (" << i << ")" << setw(5) << ans[i] << " ";
		cout << '\n';
	}
}