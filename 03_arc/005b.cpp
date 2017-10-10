#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, y;
    string W;
    cin >> x >> y >> W;

    int dx = 0;
    if (W[0] == 'R') {
      dx = 1;
    } else if (W[0] == 'L') {
      dx = -1;
    }

    int dy = 0;
    if (W[W.size() - 1] == 'D') {
      dy = 1;
    } else if (W[W.size() - 1] == 'U') {
      dy = -1;
    }

    x--;
    y--;

    string card[9];
    for (int i = 0; i < 9; i++) {
      cin >> card[i];
    }

    for (int i = 0; i < 4; i++) {
      cout << card[y][x];

      if (x + dx < 0 || x + dx > 8) {
        dx = - dx;
      }
      if (y + dy < 0 || y + dy > 8) {
        dy = - dy;
      }

      x += dx;
      y += dy;
    }
    cout << endl;
    return 0;
}
