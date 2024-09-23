#include <iostream>
#include<string>
using namespace std;
int t,n,d,b,e, arr[301];
int main() {
    cin >> t;
    for(int i = 1; i <= t; i++){
        fill(&arr[0], &arr[300], 0);
        cin >> n >> d >> b >> e;
        string result;
        int cn = n%d;
        for(int j = 0; j <= e; j++){
            cn*=7;
            arr[j] = cn/d;
            cn -= arr[j]*d;
        }
        cout << "Problem set " << i << ": " << n << " / " << d << ", base 7 digits " << b << " through " << e << ": ";
        for(int j = b; j <= e; j++) cout << arr[j];
        cout << '\n';
    }
    return 0;
}