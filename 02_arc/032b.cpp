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

using namespace std;


// Union-Find木
template <typename T>
struct UnionFind {
  int n;
  vector<T> par;
  vector<T> rank;

  explicit UnionFind(int n) {
    this-> n = n;
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

template <typename T>
vector<T> uniquify(vector<T> values) {
  sort(values.begin(), values.end());
  values.erase(unique(values.begin(), values.end()), values.end());
  return values;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  UnionFind<int> u(N);

  REP(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    u.unite(a, b);
  }

  cout << u.groups() - 1 << endl;
  return 0;
}
