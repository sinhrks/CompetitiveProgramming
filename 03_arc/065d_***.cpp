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

template <typename T>
struct UnionFind {
  vector<T> par;
  vector<T> rank;

  explicit UnionFind(int n) {
    par = vector<T>(n, 0);
    iota(par.begin(), par.end(), 0);
    rank = vector<T>(n, 0);
  }
  // 木の根を求める
  T root(T x) {
    if (par[x] ==x) {
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
  ll get(T key) {
    if (cnt.count(key)) {
      return cnt[key];
    } else {
      return 0;
    }
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
  UnionFind<int> train(N);

  for (int i = 0; i < K; i++) {
    int p, q;
    cin >> p >> q;
    p--;
    q--;
    road.unite(p, q);
  }

  for (int i = 0; i < L; i++) {
    int r, s;
    cin >> r >> s;
    r--;
    s--;
    train.unite(r, s);
  }

  Counter<pair<int, int>> c;
  for (int i = 0; i < N; i++) {
    c.add(make_pair(road.par[i], train.par[i]));
  }

  for (int i = 0; i < N; i++) {
    cout << c.get(make_pair(road.par[i], train.par[i]));
    if (i < N - 1) {
      cout << " ";
    } 
  }
  cout << endl;
  return 0;
}
