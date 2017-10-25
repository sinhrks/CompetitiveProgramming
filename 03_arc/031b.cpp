#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
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

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)

using namespace std;

int state[10][10] = {};

// 右、下、左、上
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Point {
 public:
  int x;
  int y;

  Point(int xx, int yy) {
    x = xx;
    y = yy;
  }
};

struct Searcher2D {
  int W, H;
  vector<vector<bool>> visited;
  explicit Searcher2D(int width, int height) {
    W = width;
    H = height;
    visited = vector<vector<bool>>(H, vector<bool>(W, false));
  }
  int search(int x, int y, int n) {
    // stack<Point> container;   // DFS
    queue<Point> container;      // BFS
    container.push(Point(x, y));

    while (!container.empty()) {
      // Point p = container.top();     // DFS
      Point p = container.front();      // BFS
      container.pop();

      state[p.y][p.x] = n;
      visited[p.y][p.x] = true;

      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
          if (!visited[ny][nx] && state[ny][nx] == -1) {
            // 適当な処理を追加
            container.push(Point(nx, ny));
          }
        }
      }
    }
    return n;
  }
};


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, 10) {
    string s;
    cin >> s;
    REP(j, 10) {
      if (s[j] == 'o') {
        state[i][j] = -1;
      } else {
        state[i][j] = 0;
      }
    }
  }
  Searcher2D searcher(10, 10);

  bitset<5> b;
  int n = 0;
  REP(i, 10) {
    REP(j, 10) {
      if (state[i][j] == -1) {
        n++;
        if (n >= 5) {
          cout << "NO" << endl;
          return 0;
        }
        // cout << i << " " << j << endl;
        searcher.search(j, i, n);
        // cout << n;
        b.set(n);
      }
    }
  }

  REP(i, 10) {
    REP(j, 10) {
      if (state[i][j] != 0) continue;
      bitset<5> current;
      REP(k, 4) {
        int nx = j + dx[k];
        int ny = i + dy[k];
        if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {
          if (state[ny][nx] > 0) {
            // cout << j << " " << i << " " << state[ny][nx] << endl;
            current.set(state[ny][nx]);
          }
        }
      }
      if (current == b) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;
  return 0;
}
