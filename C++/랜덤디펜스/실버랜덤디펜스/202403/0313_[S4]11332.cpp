#include <bits/stdc++.h>
#define CAL 100000000
#define MAX 10000000000
typedef long long ll;
using namespace std;

int c, t;
ll calc_fac(int n) {
    if (n <= 1) return 1;
    return calc_fac(n - 1) * n;
}
ll time(string str, ll n, ll t) {
    if (str == "O(N)") return n * t;
    else if (str == "O(N^2)") return n * n * t;
    else if (str == "O(N^3)") {
        if (n >= 1001) return MAX;
        else return n * n * n * t;
    }
    else if (str == "O(2^N)") {
        if (n >= 30) return MAX;
        else return pow(2, n) * t;
    }
    else {
        if (n >= 13) return MAX;
        else return calc_fac(n) * t;
    }
}
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> c;
    while (c--) {
        string str;
        ll n, t, l, calc;
        cin >> str >> n >> t >> l;
        calc = time(str, n, t);
        if (calc <= l * CAL) cout << "May Pass.\n";
        else cout << "TLE!\n";
    }
    return 0;
}