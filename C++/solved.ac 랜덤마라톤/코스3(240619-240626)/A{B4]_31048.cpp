#include<iostream>
using namespace std;
int arr[11], t;
int main(){
  arr[0] = 1;
  for(int i = 1; i <= 10; i++) arr[i] = (arr[i-1]*i)%10;
  cin >> t;
  while(t--){
    int k;
    cin >> k;
    cout << arr[k] << '\n';
  }
}