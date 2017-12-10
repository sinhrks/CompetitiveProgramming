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
  double t;
  double d;

  Point(int xx, int yy, double tt, double dd) {
    x = xx;
    y = yy;
    t = tt;
    d = dd;
  }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    double visited[501][501] = {};
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
        } else if (c >= '1' && c <='9') {
          state[i][j] = c - '0';
        } else if (c == '#') {
          state[i][j] = -1;
        }
        visited[i][j] = -1.;
      }
    }

    // 右、下、左、上
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    // 最短経路を見つけた後は枝刈りが効くので幅優先探索
    queue<Point> container;
    container.push(Point(sx, sy, 1., 10.));

    while (!container.empty()) {
        Point p = container.front();
        container.pop();

      double current = p.t;
      double d = p.d;

      if (state[p.y][p.x] == -1) {
        // 壁の場合
        continue;
      } else if (state[p.y][p.x] != 0) {
        // ゴールではない場合
        d = min(d, current * state[p.y][p.x]);
      }

      if (visited[gy][gx] >= d || visited[p.y][p.x] >= d) {
        // ゴール / 現在値よりも暗くなっていれば枝刈り
        continue;
      }

      visited[p.y][p.x] = d;
      current *= 0.99;
      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
          container.push(Point(nx, ny, current, d));
        }
      }
    }

    if (visited[gy][gx] == -1.) {
      cout << -1 << endl;
    } else {
      printf("%.10f\n", visited[gy][gx]);
    }
    return 0;
}
