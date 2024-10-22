#include<iostream>
#include<iomanip>
using namespace std;
int n;
int main() {
	cin >> n;
	cout << fixed << setprecision(6) << n / (double)(2*(n-1));
}