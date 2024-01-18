//#include <bits/stdc++.h>
//
//using namespace std;
//int N, num = 0;
//stack<int> st;
//vector<char> result;
//bool flag = true;
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int n;
//		cin >> n;
//
//		while (num < n) {
//			num++;
//			st.push(num);
//			result.push_back('+');
//		}
//
//		if (n == st.top()) {
//			result.push_back('-');
//			st.pop();
//		}
//		else {
//			flag = false;
//		}
//	}
//	if (flag) {
//		for (auto s : result) {
//			cout << s << '\n';
//		}
//	}
//	else{
//		cout << "NO";
//	}
//}