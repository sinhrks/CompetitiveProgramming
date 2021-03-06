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

// 累積和法 (1次元)
template <typename T>
struct Accumulator {
  vector<T> accumulated;

  explicit Accumulator(const vector<T> &values) {
    accumulated = accum_vec(values);
  }
  // from の後から to までの要素を合計する
  // (from, toは含まれる)
  T sum(int from, int to) {
    if (from == 0) {
      return accumulated[to];
    } else {
      return accumulated[to] - accumulated[from - 1];
    }
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  vector<ll> v(N, 0);
  REP(i, N) {
    cin >> v[i];
  }
  ll total = 0;
  Accumulator<ll> a(v);
  REP(i, N - K + 1) {
    total += a.sum(i, i + K - 1);
    // cout << a.sum(i, i + K - 1) << endl;
  }
  cout << total << endl;
  return 0;
}
