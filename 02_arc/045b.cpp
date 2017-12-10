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
    assert(0 <= from && from <= to);
    assert(to < accumulated.size());
    if (from == 0) {
      return accumulated[to];
    } else {
      return accumulated[to] - accumulated[from - 1];
    }
  }
};

int start[100010] = {};
int ed[100010] = {};
int sw[300010] = {};
vector<int> room;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  REP(i, M) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    start[i] = s;
    ed[i] = t;

    sw[s]++;
    sw[t + 1]--;
  }
  int overlap = 0;
  room = vector<int>(N, 0);
  REP(i, N) {
    overlap += sw[i];
    if (overlap <= 1) {
      room[i] = 1;
    }
  }

  Accumulator<int> a(room);
  vector<int> ans;
  REP(i, M) {
    if (a.sum(start[i], ed[i]) == 0) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  for (auto an : ans) {
    cout << an + 1 << endl;
  }
  return 0;
}
