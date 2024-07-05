#include<iostream>
#include<algorithm>
using namespace std;
int n, k, cnt = 0, A[500005];
void heapify(int A[], int h, int n) {
	int left = h * 2, right = h * 2 + 1, smaller;
	if (right <= n) {
		if (A[left] < A[right]) smaller = left;
		else smaller = right;
	}
	else if (left <= n) smaller = left;
	else return;
	if (A[smaller] < A[h]) {
		swap(A[h], A[smaller]);
		cnt++;
		if (cnt == k) cout << min(A[h], A[smaller]) << ' ' << max(A[h], A[smaller]);
		heapify(A, smaller, n);
	}
}
void build_min_heap(int A[], int n) {
	for (int i = n/2; i >= 1; i--) heapify(A, i, n);
}
void heap_sort(int A[]) {
	build_min_heap(A, n);
	for (int i = n; i >= 2; i--) {
		swap(A[1], A[i]);
		cnt++;
		if (cnt == k) cout << min(A[1], A[i]) << ' ' << max(A[1], A[i]);
		heapify(A, 1, i-1);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	heap_sort(A);
	if (cnt < k) cout << -1;
}