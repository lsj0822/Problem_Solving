#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool height_sort(pair<string, double> a, pair<string, double> b){
  return a.second < b.second;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    int n;
    pair<string, double> student[55];
    cin >> n;
    if(n == 0) return 0;
    for(int i = 0; i < n; i++){
      string str;
      double height;
      cin >> str >> height;
      student[i] = {str,height};
    }
    stable_sort(&student[0], &student[n], height_sort);
    double height_max = student[n-1].second;
    for(int i = 0; i < n; i++){
      if(student[i].second == height_max){
        cout << student[i].first << " ";
      }
    }
    cout << '\n';
  }
}