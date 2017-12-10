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

// カウンター
template <typename T>
struct Counter {
  map<T, ull> cnt;
  void add(T key) {
    if (cnt.count(key)) {
      cnt[key]++;
    } else {
      cnt[key] = 1;
    }
  }
  void add(vector<T> keys) {
    for (auto key : keys) {
      add(key);
    }
  }
  ll get(T key) {
    if (cnt.count(key)) {
      return cnt[key];
    } else {
      return 0;
    }
  }
  pair<T, ull> max() {
    T key;
    ull mx = 0;
    for (auto kv : cnt) {
      if (kv.second > mx) {
        mx = kv.second;
        key = kv.first;
      }
    }
    return make_pair(key, mx);
  }
};

int counts[200010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  Counter<int> c;

  REP(i, N) {
    int a;
    cin >> a;
    c.add(a);
  }
  int tot = 0;
  for (auto kv : c.cnt) {
    counts[tot++] = kv.second;
  }
  sort(counts, counts + tot);
  int ans = 0;
  REP(i, tot - K) {
    ans += counts[i];
  }

  cout << ans << endl;
  return 0;
}
