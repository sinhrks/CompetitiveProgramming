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

template <typename T>
vector<T> accum_vec(const vector<T> &values) {
  vector<T> accumulated(values.size(), 0);
  accumulated[0] = values[0];
  for (int i = 1; i < values.size(); i++) {
    accumulated[i] = accumulated[i - 1] + values[i];
  }
  return accumulated;
}

// 累積和法 (2次元)
template <typename T>
struct Accumulator2D {
  vector<vector<T>> accumulated;

  explicit Accumulator2D(const vector<vector<T>> &values) {
    accumulated = vector<vector<T>>(values.size());

    accumulated[0] = accum_vec(values[0]);
    for (int i = 1; i < values.size(); i++) {
      accumulated[i] = accum_vec(values[i]);
      for (int j = 0; j < values[i].size(); j++) {
        accumulated[i][j] += accumulated[i - 1][j];
      }
    }
  }
  // (x1, y1) の後から (x2, y2) までの要素を合計する
  // (x1, y1, x2, y2は含まれる)
  T sum(int x1, int y1, int x2, int y2) {
    assert(x1 <= x2 && x2 < accumulated[0].size());
    assert(y1 <= y2 && y2 < accumulated.size());

    T result = accumulated[y2][x2];
    if (x1 != 0) result -= accumulated[y2][x1 - 1];
    if (y1 != 0) result -= accumulated[y1 - 1][x2];
    if (x1 != 0 && y1 != 0) result += accumulated[y1 - 1][x1 - 1];
    return result;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W;
  cin >> H >> W;

  vector<vector<int>> c = vector<vector<int>>(H, vector<int>(W, 0));

  REP(i, H) {
    REP(j, W) {
      int a;
      cin >> a;
      if ((i + j) % 2 == 0) {
        c[i][j] = a;
      } else {
        c[i][j] = -a;
      }
    }
  }

  int t = 0;
  Accumulator2D<int> a(c);
  REP(h1, H) {
    REP(w1, W) {
      for (int h2 = h1; h2 < H; h2++) {
        for (int w2 = w1; w2 < W; w2++) {
          if (a.sum(w1, h1, w2, h2) == 0) {
            t = max(t, (w2 - w1 + 1) * (h2 - h1 + 1));
          }
        }
      }
    }
  }

  cout << t << endl;
  return 0;
}
