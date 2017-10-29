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

// Union-Find木
template <typename T>
struct UnionFind {
  int n;
  vector<T> rank;

 private:
  vector<T> par;

 public:
  explicit UnionFind(int n) {
    this->n = n;
    par = vector<T>(n, 0);
    iota(par.begin(), par.end(), 0);
    rank = vector<T>(n, 0);
  }
  // 木の根を求める
  T root(T x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }
  // x と y が同じ集合に属するか調べる
  bool same(T x, T y) {
    return root(x) == root(y);
  }
  // x と y が属する集合を併合する
  void unite(T x, T y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  // 所属する集合の番号を返す
  vector<int> get_group() {
    vector<int> g(n, 0);
    for (int i = 0; i < n; i++) {
      g[i] = root(i);
    }
    return g;
  }
  // 連結成分の数を数える
  int groups() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      // グループには根が自分と同じものが一つずつある
      if (par[i] == i) ans++;
    }
    return ans;
  }
};

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

  int N, K, L;
  cin >> N >> K >> L;

  UnionFind<int> road(N);
  UnionFind<int> rail(N);

  REP(i, K) {
    int p, q;
    cin >> p >> q;
    p--;
    q--;
    road.unite(p, q);
  }
  REP(i, L) {
    int r, s;
    cin >> r >> s;
    r--;
    s--;
    rail.unite(r, s);
  }

  Counter<pair<int, int>> c;
  vector<int> roadg = road.get_group();
  vector<int> railg = rail.get_group();
  REP(i, N) {
    c.add(make_pair(roadg[i], railg[i]));
  }
  REP(i, N) {
    cout << c.get(make_pair(roadg[i], railg[i]));
    if (i < N - 1) {
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}
