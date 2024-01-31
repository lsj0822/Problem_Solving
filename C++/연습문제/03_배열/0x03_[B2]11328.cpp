//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	int N;
//	cin >> N;
//	for (int i = 0; i < N;i++) {
//		string str1, str2;
//		vector<int> freq1(26), freq2(26);
//		cin >> str1 >> str2;
//		if (str1.length() != str2.length()) {
//			cout << "Impossible" << '\n';
//			continue;
//		}
//		for (int i = 0;i < str1.length();i++) {
//			freq1[str1[i] - 'a']++;
//			freq2[str2[i] - 'a']++;
//		}
//		if (freq1 == freq2) {
//			cout << "Possible";
//		}
//		else {
//			cout << "Impossible";
//		}
//		cout << '\n';
//	}
//}