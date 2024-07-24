#include<iostream>
#include<string>
#include<tuple>
#include<algorithm>
using namespace std;
int n, ans = 0, cow[3];
tuple<int, int, int> T[105];
int main() {
	cin >> n;
	cow[0] = cow[1] = cow[2] = 7;
	for (int i = 0; i < n; i++) {
		int a, b, c; string name;
		cin >> a >> name >> c;
		switch (name[0]) {
		case 'B':
			b = 0;
			break;
		case 'E':
			b = 1;
			break;
		case 'M':
			b = 2;
			break;
		}
		T[i] = make_tuple(a, b, c);
	}
	sort(&T[0], &T[n]);
	for (int i = 0; i < n; i++) {
		int day, idx, milk, prevmax, nowmax;
		bool prev_highest[3] = { false, }, now_highest[3] = { false, };
		prevmax = max({ cow[0], cow[1], cow[2] });
		for (int i = 0; i < 3; i++) { if (cow[i] == prevmax) prev_highest[i] = 1; }
		tie(day, idx, milk) = T[i];
		cow[idx] += milk;
		nowmax = max({ cow[0], cow[1], cow[2] });
		for (int i = 0; i < 3; i++) { if (cow[i] == nowmax) now_highest[i] = 1; }
		for (int i = 0; i < 3; i++) {
			if (prev_highest[i] != now_highest[i]) {
				ans++;
				break;
			}
		}
	}
	cout << ans;
}