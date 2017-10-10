#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <bitset>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

class Point {
 public:
  int x;
  int y;

  Point(int xx, int yy) {
    x = xx;
    y = yy;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);



  stack<Point> container;
  container.push(Point(x, y));

  while (!container.empty()) {
    Point p = container.top();
    container.pop();

    if (!visited[p.y][p.x]) {
      if (state[p.y][p.x] == 'g') {
        cout << "Yes" << endl;
        return 0;
      }
      if (state[p.y][p.x] != '#') {
        for (int i = 0; i < 4; i++) {
          int nx = p.x + dx[i];
          int ny = p.y + dy[i];
          if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
            container.push(Point(nx, ny));
          }
        }
      }
    }
    visited[p.y][p.x] = true;
  }

  return 0;
}
