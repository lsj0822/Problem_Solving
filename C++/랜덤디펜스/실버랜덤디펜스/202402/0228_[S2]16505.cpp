#include <iostream>
using namespace std;

int n;
char star[1025][1025];
void make_star(int dep, int x, int y) {
  if (dep == 0) {
    star[x][y] = '*';
    return;
  }
  make_star(dep - 1, x, y);
  make_star(dep - 1, x + (1 << (dep-1)), y);
  make_star(dep - 1, x, y + (1 << (dep-1)));
}
void print_star(int llen) {
  for (int i = 0; i < llen; i++) {
    for (int j = 0; j < llen - i; j++) {
      cout << star[i][j];
      }
    cout << '\n';
  }
}
int main(void)
{
  ios::sync_with_stdio(0);cin.tie(0);
  fill(&star[0][0], &star[1024][1024], ' ');
  cin >> n;
  make_star(n, 0, 0);
  print_star((1<<n));
}