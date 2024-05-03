#include <bits/stdc++.h>
using namespace std;
int n;
vector<char> l(26), r(26);
queue<char> ans;
void print() {
	while (!ans.empty()) {
		cout << ans.front();
		ans.pop();
	}
	cout << '\n';
}
void preorder(int node) {
	ans.push(node + 'A');
	if (l[node] != '.') preorder(l[node]-'A');
	if (r[node] != '.') preorder(r[node]-'A');
	if(node == 0) print();
}
void inorder(int node) {
	if (l[node] != '.') inorder(l[node] - 'A');
	ans.push(node + 'A');
	if (r[node] != '.') inorder(r[node] - 'A');
	if (node == 0) print();
}
void postorder(int node) {
	if (l[node] != '.') postorder(l[node] - 'A');
	if (r[node] != '.') postorder(r[node] - 'A');
	ans.push(node + 'A');
	if (node == 0) print();
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		l[a - 'A'] = b;
		r[a - 'A'] = c;
	}
	preorder(0);
	inorder(0);
	postorder(0);
}