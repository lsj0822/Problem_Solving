//#include <bits/stdc++.h>
//
//using namespace std;
//int N, tower[500000], result[500000], pos;
//stack<pair<int,int>> high_tower;
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> tower[i];
//	}
//
//	for (int i = 0; i < N; i++) {
//		while (!high_tower.empty()) {
//			if (tower[i] < high_tower.top().second) {
//				result[i] = high_tower.top().first + 1;
//				break;
//			}
//			high_tower.pop();
//		}
//		high_tower.push(make_pair(i, tower[i]));
//	}
//
//	for (int i = 0; i < N; i++) {
//		cout << result[i] << " ";
//	}
//}