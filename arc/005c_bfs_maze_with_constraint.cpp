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

struct Point {
  int x;
  int y;
  int d;
};

Point make_next(int x, int y, int d) {
  Point p = {x, y, d};
  return p;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    int visited[501][501] = {};
    int state[501][501] = {};

    cin >> H >> W;

    int sx, sy;
    int gx, gy;

    for ( int i = 0; i < H; i++ ) {
      for ( int j = 0; j < W; j++ ) {
        char c;
        cin >> c;
        if (c == 's') {
          sx = j;
          sy = i;
          // スタート、ゴールは0
          state[i][j] = 0;
        } else if (c == 'g') {
          gx = j;
          gy = i;
          state[i][j] = 0;
        } else if (c == '#') {
          state[i][j] = 1;
        }
        visited[i][j] = 10;
      }
    }

    // 右、下、左、上
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<Point> container;
    container.push(make_next(sx, sy, 0));

    while (!container.empty()) {
      Point p = container.front();
      container.pop();

      if (p.x == gx && p.y == gy) {
        cout << "YES" << endl;
        return 0;
      }

      int d = p.d + state[p.y][p.x];

      if (visited[p.y][p.x] <= d) {
        continue;
      } else if (d > 2) {
        continue;
      }
      visited[p.y][p.x] = d;
      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
          container.push(make_next(nx, ny, d));
        }
      }
    }

    cout << "NO" << endl;
    return 0;
}
