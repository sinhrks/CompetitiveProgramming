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
vector<int> argsort(const vector<T> &values) {
  vector<int> idx(values.size());
  iota(idx.begin(), idx.end(), 0);

  sort(idx.begin(), idx.end(),
       [&values](size_t i1, size_t i2) { return values[i1] > values[i2]; });

  return idx;
}

// Union-Find木
template <typename T>
struct UnionFind {
  int n;
  vector<T> rank;

 private:
  // それぞれの親を保持
  // 集合を取得したい場合は root / get_group を使う
  vector<T> par;
  // 集合の大きさを保持
  vector<int> siz;

 public:
  explicit UnionFind(int n) {
    this->n = n;
    par = vector<T>(n, 0);
    iota(par.begin(), par.end(), 0);
    rank = vector<T>(n, 0);
    siz = vector<T>(n, 1);
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
      siz[y] += siz[x];
    } else {
      par[y] = x;
      siz[x] += siz[y];
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
  // 所属する集合の大きさを返す
  int get_group_size(T x) {
    return siz[root(x)];
  }
  // 集合の数を数える
  int groups() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      // 集合には根が自分と同じものが一つずつあるため、それを数えれば良い
      if (par[i] == i) ans++;
    }
    return ans;
  }
};

vector<int> A;
vector<int> B;
vector<int> Y;

vector<int> V;
vector<int> W;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  A = vector<int>(M, 0);
  B = vector<int>(M, 0);
  Y = vector<int>(M, 0);

  REP(i, M) {
    cin >> A[i] >> B[i] >> Y[i];
    A[i]--;
    B[i]--;
  }

  int Q;
  cin >> Q;

  V = vector<int>(Q, 0);
  W = vector<int>(Q, 0);

  REP(i, Q) {
    cin >> V[i] >> W[i];
    V[i]--;
  }

  vector<int> nidx = argsort(Y);
  vector<int> qidx = argsort(W);

  int nx = 0;
  UnionFind<int> u(N);
  vector<int> ans(Q, 0);

  REP(i, qidx.size()) {
    int v = V[qidx[i]];
    int w = W[qidx[i]];

    // cout << "x: " << v << " " << w << endl;
    while (nx < nidx.size() && Y[nidx[nx]] > w) {
      // cout << Y[nidx[nx]] << endl;
      // cout << endl;
      u.unite(A[nidx[nx]], B[nidx[nx]]);
      nx++;
    }
    ans[qidx[i]] = u.get_size(v);
  }
  // DEBUG(ans);

  for (auto a : ans) {
    cout << a << endl;
  }
  return 0;
}
