//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	string str1, str2;
//	vector<int> f1(26), f2(26);
//	int r = 0;
//	cin >> str1 >> str2;
//	for (auto s1 : str1) {
//		f1[s1 - 'a']++;
//	}
//	for (auto s2 : str2) {
//		f2[s2 - 'a']++;
//	}
//	for (int i = 0; i < 26; i++) {
//		r += abs(f1[i] - f2[i]);
//	}
//	cout << r;
//}