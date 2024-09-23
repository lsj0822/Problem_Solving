#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
string str;
stack<int> st;
int a, b;
bool res = 1;
int main() {
	cin >> str;
	reverse(str.begin(), str.end());
	for (char c : str) {
		switch (c) {
		case 'x':
			st.push(0);
			break;
		case 'g':
			if (st.empty()) {
				res = 0;
				break;
			}
			else {
				a = st.top(); st.pop();
				st.push(++a);
			}
			break;
		case 'f':
			if (st.size() <= 1) {
				res = 0;
				break;
			}
			else {
				int a, b;
				a = st.top(); st.pop();
				b = st.top(); st.pop();
				st.push(min(a, b));
			}
			break;
		}
	}
	if (st.size() != 1 || res == 0) cout << -1;
	else cout << st.top();
}