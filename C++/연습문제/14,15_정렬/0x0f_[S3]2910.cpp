#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

vector<pair<int,int>> arr;
int n, c;

bool method(pair<int, int> a, pair<int, int> b) {
	return a.Y > b.Y;
}

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		bool flag = true;
		for (auto &cur : arr) {
			if (cur.X == k) {
				cur.Y++;
				flag = false;
				break;
			}
		}
		if (flag) arr.push_back({ k,1 });
	}
	stable_sort(arr.begin(), arr.end(), method);
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].Y; j++) {
			cout << arr[i].X << " ";
		}
	}
}