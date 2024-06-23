#include <iostream>
#include<string>
using namespace std;
int arr[200005], parent[100001], n;
int main() {
    cin >> n;
    fill(&parent[0], &parent[100001], -1);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i < n; i++){
        if(parent[arr[i]] >= 0) continue;
        parent[arr[i]] = arr[i-1];
    }
    parent[arr[0]] = -1;
    cout << (n+1)/2 << '\n';
    for(int i = 0; i < (n+1)/2; i++) cout << parent[i] << ' ';
    return 0;
}