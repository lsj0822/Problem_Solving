#include<iostream>
using namespace std;
long long n;
int main() {
	cin >> n;
	cout << (n == 1 ? 2 : 1);
	/* 증명 : 다항식의 나눗셈을 이용하여 증명 가능
	x = 2라고 했을 시, n = 1은 x를 x + 1로 나누는 것이므로 나머지는 -1(2)
	이후에는 n = 2부터는 x의 짝수제곱으로 다항식이 표현되어있으므로 나머지는 (-1)^2n = 1*/
}