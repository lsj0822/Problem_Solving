#include <bits/stdc++.h>

using namespace std;
string str, arr[1005];
int main() {
	cin >> str;
	int strlen = str.size();
	for (int i = 0; i < strlen; i++) {
		arr[i] = str.substr(i);
	}
	sort(&arr[0], &arr[strlen]);
	for (int i = 0; i < strlen; i++) {
		cout << arr[i] << '\n';
	}
}