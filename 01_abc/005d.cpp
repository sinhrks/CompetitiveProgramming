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
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

template <typename T>
vector<T> accum_vec(const vector<T> &values) {
  vector<T> accumulated(values.size(), 0);
  accumulated[0] = values[0];
  for (int i = 1; i < static_cast<int>(values.size()); i++) {
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
    for (int i = 1; i < static_cast<int>(values.size()); i++) {
      accumulated[i] = accum_vec(values[i]);
      for (int j = 0; j < static_cast<int>(values[i].size()); j++) {
        accumulated[i][j] += accumulated[i - 1][j];
      }
    }
  }
  // (x1, y1) の後から (x2, y2) までの要素を合計する
  // (x1, y1, x2, y2は含まれる)
  T sum(int x1, int y1, int x2, int y2) {
    assert(x1 <= x2 && x2 < static_cast<int>(accumulated[0].size()));
    assert(y1 <= y2 && y2 < static_cast<int>(accumulated.size()));

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

  int N;
  cin >> N;

  vector<vector<int>> d = vector<vector<int>>(N, vector<int>(N, 0));

  REP(i, N) {
    REP(j, N) {
      cin >> d[i][j];
    }
  }
  Accumulator2D<int> a(d);

  int Q;
  cin >> Q;
  int P[2510] = {};

  REP(i, Q) {
    cin >> P[i];
  }
  REP(i, Q) {
    int p = P[i];
    int mx = 0;
    for (int k = 1; k <= p; k++) {
      int w = min(N, k);
      int h = min(N, p / w);
      REP(i, N - h + 1) {
        REP(j, N - w + 1) {
          mx = max(mx, a.sum(j, i, j + w - 1, i + h - 1));
        }
      }
    }
    cout << mx << endl;
  }

  return 0;
}
