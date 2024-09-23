#include <iostream>
#include <string>
using namespace std;
int n;
pair<int,int> speed[105], res = {-1e7, 1e7};
string signal[105];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> signal[i] >> speed[i].first >> speed[i].second;
    for(int i = n-1; i >= 0; i--){
        if(signal[i] == "on") {res.first = max(0, res.first - speed[i].second); res.second -= speed[i].first;}
        if(signal[i] == "off") {res.first += speed[i].first; res.second += speed[i].second;}
        if(signal[i] == "none") {res.first = max(res.first, speed[i].first); res.second = min(res.second, speed[i].second);}
        }
    cout << res.first << ' ' << res.second << '\n';
    res = {-1e7,1e7};    
    for(int i = 0; i < n; i++){
        if(signal[i] == "off") {res.first = max(0, res.first - speed[i].second); res.second -= speed[i].first;}
        if(signal[i] == "on") {res.first += speed[i].first; res.second += speed[i].second;}
        if(signal[i] == "none") {res.first = max(res.first, speed[i].first); res.second = min(res.second, speed[i].second);}
    }
   cout << res.first << ' ' << res.second; 
}