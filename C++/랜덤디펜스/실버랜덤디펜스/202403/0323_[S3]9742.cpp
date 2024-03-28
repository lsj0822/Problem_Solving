#include <bits/stdc++.h>
using namespace std;

int fac(int n) {
    if (n == 0) return 1;
    return n * fac(n - 1);
}
int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    while (1) {
        vector<char> vec;
        string str; int n;
        cin >> str >> n;
        if (cin.eof()) return 0;
        cout << str << ' ' << n << " = ";
        for (auto c : str) {
            vec.push_back(c);
        }
        if (n > fac(str.length())) cout << "No permutation\n";
        else {
            for (int i = 0; i < n-1; i++)next_permutation(vec.begin(), vec.end());
            for (char c : vec) cout << c;
            cout << '\n';
        }
    }
}