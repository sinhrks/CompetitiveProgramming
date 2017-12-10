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

# define INF 0x3f3f3f3f

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

# define MOD 1000000007

int problems[100010] = {};

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
    assert(0 <= from && from <= to);
    assert(to < static_cast<int>(accumulated.size()));
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

  int S = 100000;

  int N;
  cin >> N;
  REP(i, N) {
    int d;
    cin >> d;
    problems[d]++;
  }

  // Accumulator<int> a(problems);

  ll ans = 0;
  REP(p2, S) {
    // if (problems[p2] == 0) continue;
    for (int p3 = p2 * 2; p3 < S; p3++) {
      ll tmp = 1;
      // tmp *= a.sum(0, p2 / 2) % MOD;
      // tmp *= a.sum(min(p3 * 2, S), S) % MOD;
      ans += tmp;
      ans %= MOD;
    }
  }

  cout << ans << endl;
  return 0;
}
