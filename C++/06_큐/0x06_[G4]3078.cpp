#include <bits/stdc++.h>

using namespace std;
int N, K, name[21];
long long result;
queue<int> fr;
int main() {
	cin >> N >> K;
	while (N--) {
		string student;
		int sl;
		cin >> student;
		sl = student.length();
		if (fr.size() == K + 1) {
			name[fr.front()]--;
			fr.pop();
		}
		result += name[sl];
		name[sl]++;
		fr.push(sl);
	}
	cout << result;
}