#include<iostream>
#include<string>
using namespace std;
string str, s[4] = { "North London Collegiate School","Branksome Hall Asia", "Korea International School", "St. Johnsbury Academy" };
int main() {
	cin >> str;
	switch (str[0]) {
	case 'N': cout << s[0]; break;
	case 'B': cout << s[1];	break;
	case 'K': cout << s[2]; break;
	case 'S': cout << s[3]; break;
	}
}