//#include <bits/stdc++.h>
//
//using namespace std;
//
//int tower[80000], N;
//long long result = 0;
//stack<pair<int, int>> tall;
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> tower[i];
//	}
//
//	for (int i = N - 1; i >= 0; i--) {
//		while (!tall.empty()) {
//			if (tower[i] <= tall.top().second) {
//				result += tall.top().first - i - 1;
//				break;
//			}
//			tall.pop();
//		}
//		if (tall.empty()) {
//			result += N - 1 - i;
//		}
//		tall.push(make_pair(i, tower[i]));
//	}
//	cout << result;
//}