#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <array>
#include <vector>
typedef long long ll;

using namespace std;

// Union Find
#define MAX_N 100000

template <typename T>
class UnionFind {
 private:
  array<T, MAX_N> par;
  array<T, MAX_N> rank;
 public:
  void init(int n);
  T root(T x);
  bool same(T x, T y);
  void unite(T x, T y);
};

// 初期化
template <typename T>
void UnionFind<T>::init(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rank[i] = 0;
  }
}

// 木の根を求める
template <typename T>
T UnionFind<T>::root(T x) {
  if (par[x] ==x) {
    return x;
  } else {
    return par[x] = root(par[x]);
  }
}

// x と y が同じ集合に属するか調べる
template <typename T>
bool UnionFind<T>::same(T x, T y) {
  return root(x) == root(y);
}

// x と y が属する集合を併合する
template <typename T>
void UnionFind<T>::unite(T x, T y) {
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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    UnionFind<int> u;
    u.init(N);

    for (int i = 0; i < Q; i++) {
      int p, a, b;
      cin >> p >> a >> b;

      if (p == 0) {
        u.unite(a, b);
      } else if (p == 1) {
        if (u.same(a, b)) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      }
    }
    return 0;
}
