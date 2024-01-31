#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	stack<int> st;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int n;
			cin >> n;
			st.push(n);
		}
		else if (str == "pop") {
			if (st.empty())cout << -1;
			else { 
				cout << st.top();
				st.pop();
			}
			cout << '\n';
		}
		else if (str == "size") {
			cout << st.size() << '\n';
		}
		else if (str == "top") {
			if (st.empty())cout << -1;
			else cout << st.top();
			cout << '\n';
		}
		else {
			cout << static_cast<int>(st.empty()) << '\n';
		}

	}
}