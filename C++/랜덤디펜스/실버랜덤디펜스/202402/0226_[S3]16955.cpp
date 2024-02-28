#include <iostream>
#include <string>
using namespace std;

string board[10];
bool check_omok(){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j <= 5; j++){
      bool vres = true, hres = true;
      //vertical
      for(int k = 0; k < 5; k++){
        if(board[i][j+k] != 'X') {
          vres = false;
          break;
        }
      }
      //horizonal
      for(int k = 0; k < 5; k++){
        if(board[j+k][i] != 'X'){
          hres = false;
          break;
        }
      }
      if(hres || vres) return true;
    }
  }
  for(int i = 0; i <= 5; i++){
    for(int j = 0; j <= 5; j++){
      int dres = true, adres = true;
      //diagonal
      for(int k = 0; k < 5; k++){
        if(board[i+k][j+k] != 'X'){
          dres = false;
          break;
        }
      }
      //antidiagonal
      for(int k = 0; k < 5; k++){
        if(board[i+k][j+4-k] != 'X'){
          adres = false;
          break;
        }
      }
      if(dres || adres) return true;
    }
  }
  return false;
}
int main(void)
{
  for(int i = 0; i < 10; i++){
    cin >> board[i];
  }
  for(int i = 0; i < 100; i++){
    if(board[i/10][i%10] == '.'){
      board[i/10][i%10] = 'X';
      if(check_omok()){
        cout << 1;
        return 0;
      }
      board[i/10][i%10] = '.';
    }
  }
  cout << 0;
  return 0;
}