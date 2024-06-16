#include <iostream>
using namespace std;
int gun[202], emma[202], a1, b1, a2, b2, res = 0;
int main() {
    cin >> a1 >> b1 >> a2 >> b2;
    for(int i = a1; i <= b1; i++){
        for(int j = a2; j <= b2; j++){
            gun[i+j]++;
        }
    }
    cin >> a1 >> b1 >> a2 >> b2;
    for(int i = a1; i <= b1; i++){
        for(int j = a2; j <= b2; j++){
            emma[i+j]++;
        }
    }
    for(int i = 2; i <= 200; i++){
        for(int j = 2; j <= 200; j++){
            if(i == j) continue;
            res += gun[i]*emma[j]*abs(i-j)/(i-j);
        }
    }
    if(res > 0) cout << "Gunnar";
    else if(res < 0) cout << "Emma";
    else cout << "Tie";
}