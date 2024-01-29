#include<iostream>
using namespace std;
int n, s, r = 0;
int num[20];
void bt(int sum, int len) {
	if (len == n) {
		if(sum == s){
		r++;
		return;
		}
	}
	else {
		bt(sum, len + 1);
		bt(sum + num[len], len + 1);
	}
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	bt(0,0);
	if (s == 0) r--;
	cout << r;
}