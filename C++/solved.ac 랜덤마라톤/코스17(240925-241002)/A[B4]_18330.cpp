#include<iostream>
using namespace std;
int n, k;
int main() {
	cin >> n >> k;
	cout << (n >= k + 60 ? (k + 60) * 1500 + (n - k - 60) * 3000 : n * 1500);
}