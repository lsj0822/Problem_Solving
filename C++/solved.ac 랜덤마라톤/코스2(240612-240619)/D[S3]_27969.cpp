#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
int main() {
	queue<string> Q;
	stack<long long> ST;
	string str, tmp;
	stringstream ss;
	long long ans = 0;
	getline(cin, str);
	ss.str(str);
	while (ss >> tmp) Q.push(tmp);
	while (!Q.empty()) {
		string s = Q.front(); Q.pop();
		if (s == "[") {
			ST.push(ans);
			ans = 0;
		}
		else if (s == "]") {
			ans += ST.top() + 8;
			ST.pop();
		}
		else if (s[0] >= '1' && s[0] <= '9') ans += 8;
		else ans += 12 + s.size();
	}
	cout << ans;
}