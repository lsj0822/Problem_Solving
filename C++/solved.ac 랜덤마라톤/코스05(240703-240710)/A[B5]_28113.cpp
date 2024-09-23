#include <iostream>
using namespace std;
int n,a,b;
int main() {
    cin >> n >> a >> b;
    cout << ((a==b)?"Anything":(a>b)?"Subway":"Bus");
    return 0;
}