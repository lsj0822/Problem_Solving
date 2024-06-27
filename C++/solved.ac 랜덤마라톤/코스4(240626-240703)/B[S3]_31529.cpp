#include <iostream>
#include <string>
using namespace std;
int n, m;
int main() {
    cin >> n >> m;
    if(n > m || (2*n - m) < 0) cout << -1;
    else cout << 506 * (2*n-m);
    return 0;
}