#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int MAX = 1e5 + 5;
int arr[MAX];
int h = (int)ceil(log2(MAX));
vector<int> tree((2 << h), 1);
char res[3] = { '-','0','+' };

void init(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		init(node * 2, start, mid);
		init(node * 2 + 1, mid + 1, end);
		tree[node] = tree[node * 2] * tree[node * 2 + 1];
	}
}

void update(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		arr[idx] = val;
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 1;
	if (left <= start && end <= right) return tree[node];
	int lres, rres, mid = (start+end)/2;
	lres = query(node * 2, start, mid, left, right);
	rres = query(node * 2 + 1, mid + 1, end, left, right);
	return lres * rres;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	while (cin >> n >> k) {
		string ans = "";
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			arr[i] = (num == 0 ? 0 : num / abs(num));
		}
		init(1, 0, n - 1);
		for (int i = 0; i < k; i++) {
			char a; int b, c;
			cin >> a >> b >> c;
			switch (a) {
			case 'C':
				c = (c == 0 ? 0 : c / abs(c));
				update(1, 0, n - 1, b - 1, c);
				break;
			case 'P':
				int q = query(1, 0, n - 1, b - 1, c - 1);
				ans += res[q + 1];
				break;
			}
		}
		cout << ans << '\n';
	}
}