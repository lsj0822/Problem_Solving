#include<bits/stdc++.h>
using namespace std;
int n, ans = -1, endnode;
bool endfind = false;
vector<int> l(100005), r(100005), p(100005);
vector<bool> vst(100005);
int find_end(int node) {
	if (r[node] == -1) return node;
	else return find_end(r[node]);
}
void inorder(int node) {
	ans++;
	vst[node] = 1;
	if (l[node] != -1 && !vst[l[node]]) inorder(l[node]);
	else if (r[node] != -1 && !vst[r[node]]) inorder(r[node]);
	else if (node == endnode) return;
	else if (p[node] != -1) inorder(p[node]);
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		l[a] = b; r[a] = c;
		if (b != -1) p[b] = a;
		if (c != -1) p[c] = a;
	}
	endnode = find_end(1);
	inorder(1);
	cout << ans;
}