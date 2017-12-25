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
  typename map<T, ll>::iterator begin() {
    return cnt.begin();
  }
  typename map<T, ll>::iterator end() {
    return cnt.end();
  }
  typename map<T, ll>::reverse_iterator rbegin() {
    return cnt.rbegin();
  }
  typename map<T, ll>::reverse_iterator rend() {
    return cnt.rend();
  }
};


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  Counter<int> c;
  REP(i, N) {
    int a;
    cin >> a;
    c.add(a);
  }
  ll ans = 0;
  for (auto kv : c.cnt) {
    // cout << kv.first << " " << kv.second << endl;
    if (kv.first < kv.second) {
      ans += kv.second - kv.first;
    }
    if (kv.first > kv.second) {
      ans += kv.second;
    }
  }

  cout << ans << endl;
  return 0;
}
