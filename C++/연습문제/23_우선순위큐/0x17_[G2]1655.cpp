#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> lessPQ;
priority_queue<int, vector<int>, greater<int>> greatPQ;
int n, crit, k;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin >> k;
	crit = k;
	cout << crit << '\n';
	for (int i = 1; i < n; i++) {
		//기준을 바탕으로 작은 값을 모으는 우선순위 큐, 큰 값을 모으는 우선순위 큐를 만든다.
		//값의 불균형이 일어나면 최우선순위의 원소로 기준을 바꾼다.
		cin >> k;
		if (k < crit) lessPQ.push(k);
		else greatPQ.push(k);
		if (lessPQ.size() > greatPQ.size()) {
			greatPQ.push(crit);
			crit = lessPQ.top();
			lessPQ.pop();
		}
		else if (lessPQ.size() + 1 < greatPQ.size()) {
			lessPQ.push(crit);
			crit = greatPQ.top();
			greatPQ.pop();
		}
		cout << crit << '\n';
	}
}