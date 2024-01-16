//#include <bits/stdc++.h>
//
//using namespace std;
//int main() {
//	int sum=1;
//	for (int i = 0;i < 3;i++) {
//		int n;
//		cin >> n;
//		sum *= n;
//	}
//	vector<int> result(10, 0);
//	while (sum > 0) {
//		result[sum % 10]++;
//		sum /= 10;
//	}
//	for (auto k : result) {
//		cout << k << '\n';
//	}
//}