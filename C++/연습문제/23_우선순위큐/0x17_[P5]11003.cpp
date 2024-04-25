//우선순위 큐를 이용한 풀이

#include <iostream>
#include <queue>
using namespace std;
int n, l;
class DQsort {
public:
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.first > b.first;
	}
};
priority_queue < pair<int, int>, vector<pair<int, int>>, DQsort> DQ;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int k; 
		cin >> k;
		DQ.push({ k,i });
		while (1) {
			if (i - DQ.top().second >= l) DQ.pop();
			else break;
		}
		cout << DQ.top().first << ' ';
	}
}