#include <bits/stdc++.h>

using namespace std;

long long arr[1000005];
int n;
string str;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		reverse(str.begin(), str.end());
		arr[i] = stoll(str);
	}
	sort(&arr[0], &arr[n]);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}