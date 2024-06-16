#include <iostream>
#include <queue>
using namespace std;
int pos[40005], e, l, b;
int main() {
    cin >> e >> l >> b;
    while(b--){
        int k;
        cin >> k;
        pos[k] = -1;
    }
    queue<int> BFS;
    BFS.push(0);
    while(1){
        int p = BFS.front(); BFS.pop();
        if(p == e) break;
        for(int i = 1; i <= l; i++){
            if(pos[p+i] != 0) continue;
            pos[p+i] = pos[p] + 1;
            BFS.push(p+i);
        }
    }
    cout << pos[e];
}