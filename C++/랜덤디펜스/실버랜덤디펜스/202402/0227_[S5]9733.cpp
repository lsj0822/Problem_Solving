#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

string labor[7] = { "Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex" };
int lcnt[7];
double total = 0;
int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  string str;
  while (getline(cin, str)) {
    stringstream stream(str);
    string s;
    while (stream >> s) {
      lcnt[find(&labor[0], &labor[7], s) - &labor[0]]++;
      total += 1;
    }
  }
  for(int i = 0; i < 7; i++){
    cout << labor[i] << " " << lcnt[i] << " " << fixed << setprecision(2) << lcnt[i]/double(total) << '\n';
  }
  cout << "Total " << int(total) << " 1.00\n";
  return 0;
}