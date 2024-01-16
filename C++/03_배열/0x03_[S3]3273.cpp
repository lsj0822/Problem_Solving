//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	vector<int> visited(2000001);
//	int n, x, result = 0;
//	cin >> n;
//	vector<int> container(n);
//	for (int i = 0; i < n; i++) {
//		int k;
//		cin >> k;
//		container[i] = k;
//	}
//	cin >> x;
//	for (int k : container) {
//		if (x-k>=0 && visited[x - k]) { result++; }
//		visited[k]++;
//	}
//	cout << result;
//}