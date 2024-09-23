#include <iostream>
#include <queue>
#define ll long long
using namespace std;
ll sugar, pack = 0;
int main(){
    cin >> sugar;
    while(1){
        if(sugar%5 == 0){
            pack += sugar/5;
            break;
        }
        else if(sugar <= 4 && sugar%3 != 0){
            pack = -1;
            break;
        }
        pack++;
        sugar -= 3;
    }
    cout << pack;
}