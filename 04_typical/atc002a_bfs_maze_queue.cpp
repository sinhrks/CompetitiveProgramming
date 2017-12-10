#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
typedef long long ll;

using namespace std;

class Point {
 public:
  int x;
  int y;
  int d;

  Point(int xx, int yy, int dd) {
    x = xx;
    y = yy;
    d = dd;
  }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, sy, sx, gy, gx;
    int visited[51][51] = {};
    bool state[51][51] = {};

    cin >> H >> W;
    cin >> sy >> sx;
    cin >> gy >> gx;

    sy--;
    sx--;
    gy--;
    gx--;

    for ( int i = 0; i < H; i++ ) {
      for ( int j = 0; j < W; j++ ) {
        char c;
        cin >> c;
        if (c == '.') {
          state[i][j] = true;
        }
        visited[i][j] = -1;
      }
    }

    // 右、下、左、上
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<Point> container;
    container.push(Point(sx, sy, 0));

    while (!container.empty()) {
      Point p = container.front();
      container.pop();

      if (visited[p.y][p.x] == -1) {
        if (p.x == gx && p.y == gy) {
          cout << p.d << endl;
          return 0;
        }
        if (state[p.y][p.x]) {
          for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
              container.push(Point(nx, ny, p.d + 1));
            }
          }
        }
      }
      visited[p.y][p.x] = true;
    }
    return 0;
}
