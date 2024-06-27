#include<iostream>
#include<algorithm>
using namespace std;
int t;
int main() {
	cin >> t;
	while (t--) {
		int arr[3];
		for (int i = 0; i < 3; i++) cin >> arr[i];
		sort(&arr[0], &arr[3]);
		cout << arr[2] - arr[0] << '\n';
	}
}
