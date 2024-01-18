//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	int N, result = 0;
//	cin >> N;
//	stack<int> st;
//	while (N--) {
//		int n;
//		cin >> n;
//		if (n > 0) st.push(n);
//		else st.pop();
//	}
//	while (!st.empty()) {
//		result += st.top();
//		st.pop();
//	}
//	cout << result;
//}