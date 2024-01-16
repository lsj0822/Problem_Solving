//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	vector<int> info(13);
//	int N, K, room = 0;
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		int S, Y;
//		cin >> S >> Y;
//		info[S * 6 + Y]++;
//	}
//	for (int r : info) {
//		if (r > 0) {
//			room += (r - 1) / K + 1;
//		}
//	}
//	cout << room;
//}