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


template <typename T>
class UnionFind {
 private:
  vector<T> par;
  vector<T> rank;
 public:
  explicit UnionFind(int n) {
    for (int i = 0; i < n; i++) {
      par.push_back(i);
      rank.push_back(0);
    }
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    UnionFind<int> u = UnionFind<int>(N);

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
