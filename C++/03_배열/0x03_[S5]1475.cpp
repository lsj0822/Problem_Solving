//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	vector<int> p(10);
//	int k, vmax = 0;
//	cin >> k;
//	while (k > 0) {
//		p[k % 10]++;
//		k /= 10;
//	}
//	p[6] = (p[6] + p[9]+1) / 2;
//	p[9] = 0;
//	for (int f : p) {
//		vmax = max(f, vmax);
//	}
//	cout << vmax;
//}