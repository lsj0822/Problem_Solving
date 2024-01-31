#include <iostream>
using namespace std;

bool detect(string str){
  int length = str.length();
  if (length <= 2) return true;
  int container[85];
  for(int i = 1; i < length; i++){
    container[0] = str[0]*100 + str[i];
    for(int j = 1; j < length-i; j++){
      int compare = str[j]*100 + str[i+j];
      for(int k = 0; k < j; k++){
        if(compare == container[k]) return false;
      }
      container[j] = compare;
    }
  }
  return true;
}

int main(void)
{
  while(true){
    string str;
    cin >> str;
    if (str == "*") break;
    if(detect(str)) cout << str << " is surprising.\n";
    else cout << str << " is NOT surprising.\n";
  }
  return 0;
}