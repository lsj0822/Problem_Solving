#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class pq_sort {
public:
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second != b.second) return a.second < b.second;
		else return a.first < b.first;
	}
};

priority_queue< pair<int, int>, vector<pair<int, int>>, pq_sort> PQ;
pair<int, int> ramen[200005];
int n, ans = 0, idx = 0;

bool ramen_sort(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		ramen[i] = { a,b };
	}
	sort(&ramen[0], &ramen[n], ramen_sort);
	for (int i = n; i >= 1; i--) {
		while (1) {
			if (ramen[idx].first == i) PQ.push(ramen[idx++]);
			else break;
		}
		if (!PQ.empty()) {
			ans += PQ.top().second;
			PQ.pop();
		}
	}
	cout << ans;
}