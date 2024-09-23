#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> node[8], result;
int deg[8];
priority_queue<int, vector<int> , greater<int>> Q;
void preload(){
	pair<int,int> pre[5] = {{1,7},{1,4},{2,1},{3,4},{3,5}};
	for (int i = 0; i < 5; i++) {
		node[pre[i].first].push_back(pre[i].second);
		deg[pre[i].second]++;
	}
}
int main() {
	preload();
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		node[a].push_back(b);
		deg[b]++;
	}
	for (int i = 1; i <= 7; i++) {
		if (deg[i] == 0) Q.push(i);
	}
	while (!Q.empty()) {
		int cur = Q.top(); Q.pop();
		result.push_back(cur);
		for (int v : node[cur]) {
			deg[v]--;
			if (deg[v] == 0) Q.push(v);
		}
	}
	if (result.size() != 7) cout << "Cannot complete these tasks. Going to bed.";
	else {
		for (int i = 0; i < 7; i++) cout << result[i] << ' ';
	}
}