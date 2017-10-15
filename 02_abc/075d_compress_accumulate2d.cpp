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

using namespace std;

// 座標圧縮
template <typename T>
struct Compressor {
  map<T, int> compressor;
  vector<int> extractor;

  explicit Compressor(vector<T> originals) {
    sort(originals.begin(), originals.end());
    originals.erase(unique(originals.begin(), originals.end()),
                    originals.end());

    extractor = vector<int>(originals.size(), 0);
    for (int i = 0; i < originals.size(); i++) {
      compressor[originals[i]] = i;
      extractor[i] = originals[i];
    }
  }

  int compress(T value) {
    return compressor[value];
  }
  vector<int> compress(const vector<T> &values) {
    // <int> を返したいので for_each は使えない
    vector<int> results(values.size());
    for (int i = 0; i < values.size(); i++) {
      results[i] = compressor[i];
    }
    return results;
  }
  T extract(int index) {
    return extractor[index];
  }
};

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

  ll N, K;
  cin >> N >> K;

  vector<ll> x(N, 0);
  vector<ll> y(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    cin >> y[i];
  }

  Compressor<ll> xc(x);
  Compressor<ll> yc(y);

  vector<vector<int>> v(N);
  for (int i = 0; i < N; i++) {
    v[i] = vector<int>(N, 0);
  }
  for (int i = 0; i < N; i++) {
    v[yc.compress(y[i])][xc.compress(x[i])] = 1;
  }

  Accumulator2D<int> a(v);

  ull area = ULLONG_MAX;
  for (int xi = 0; xi < N; xi++) {
    for (int xj = xi + 1; xj < N; xj++) {
      for (int yi = 0; yi < N; yi++) {
        for (int yj = yi + 1; yj < N; yj++) {

          if (a.sum(xi, yi, xj, yj) == K) {
            ll xx = xc.extract(xj) - xc.extract(xi);
            ll yy = yc.extract(yj) - yc.extract(yi);
            ull tmp = xx * yy;

            area = min(area, tmp);
          }
        }
      }
    }
  }

  cout << area << endl;
  return 0;
}
