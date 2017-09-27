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

  Point(int xx, int yy) {
    x = xx;
    y = yy;
  }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    bool visited[501][501] = {};
    char state[501][501] = {};

    cin >> H >> W;

    int x, y;

    for ( int i = 0; i < H; i++ ) {
      for ( int j = 0; j < W; j++ ) {
        char c;
        cin >> c;
        state[i][j] = c;
        if (c == 's') {
          x = j;
          y = i;
        }
      }
    }

    // 右、下、左、上
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

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
    cout << "No" << endl;
    return 0;
}
