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

# define INF 0x3f3f3f3f

template <typename T>
struct Edge {
  int src, dst;
  T weight;
  Edge(int src, int dst, T weight) :
    src(src), dst(dst), weight(weight) { }
};
template <typename T>
bool operator < (const Edge<T> &e, const Edge<T> &f) {
  return e.weight != f.weight ? e.weight > f.weight :
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

template <typename T>
struct Graph {
  int V;    // 頂点数
  vector<Edge<T>> *adj;
  bool directed;

  explicit Graph(int V, bool directed) {
    this->V = V;
    this->adj = new vector<Edge<T>> [V];
    this->directed = directed;
  }
  // 辺を追加
  void add_edge(int src, int dst, T weight) {
    assert(src >= 0 && src < V);
    assert(dst >= 0 && dst < V);

    adj[src].push_back(Edge<T>(src, dst, weight));
    if (!directed) {
      adj[dst].push_back(Edge<T>(dst, src, weight));
    }
  }
  // 辺があるかチェック
  bool has_edge(int src, int dst) {
    return any_of(adj[src].begin(), adj[src].end(),
                  [dst](Edge<T> e) { return e.dst == dst; });
  }
  // 辺の重みをチェック
  T get_weight(int src, int dst) {
    for (const auto &e : adj[src]) {
      if (e.dst == dst) {
        return e.weight;
      }
    }
    return INF;
  }
  ll get_total_weights() {
    ll result = 0;
    for (int i = 0; i < V; i++) {
      for (const auto &e : adj[i]) {
        result += e.weight;
      }
    }
    return result;
  }
  // 辺を削除
  void remove_edge(int src, int dst) {
    adj[src].erase(remove_if(adj[src].begin(), adj[src].end(),
                             [dst](Edge<T> e) { return e.dst == dst; }),
                   adj[src].end());

    if (!directed) {
      adj[dst].erase(remove_if(adj[dst].begin(), adj[dst].end(),
                              [src](Edge<T> e) { return e.dst == src; }),
                     adj[dst].end());
    }
  }
  // 連結判定
  bool is_connected() {
    vector<bool> visited(V, false);
    queue<int> container;
    container.push(0);

    while (!container.empty()) {
      int p = container.front();
      container.pop();
      visited[p] = true;
      for (const auto &e : adj[p]) {
        if (!visited[e.dst]) {
          container.push(e.dst);
        }
      }
    }
    return all_of(visited.begin(), visited.end(),
                  [](bool v) { return v; });
  }
  Graph<T> spanning_tree();
};

// Union-Find木
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

// 最小全域木(クラスカル法)
template <typename T>
Graph<T> Graph<T>::spanning_tree() {
  Graph<T> result(V, false);
  UnionFind<int> u = UnionFind<int>(V);

  priority_queue<Edge<T>> pq;
  for (int i = 0; i < V; i++) {
    for (const auto& e : adj[i]) {
      pq.push(e);
    }
  }

  while (!pq.empty()) {
    Edge<T> e = pq.top();
    pq.pop();

    if (!u.same(e.src, e.dst)) {
      u.unite(e.src, e.dst);
      result.add_edge(e.src, e.dst, e.weight);
    }
  }
  return result;
}

template <typename T>
vector<int> argsort(const vector<T> &values) {
  vector<int> idx(values.size());
  iota(idx.begin(), idx.end(), 0);

  sort(idx.begin(), idx.end(),
       [&values](size_t i1, size_t i2) { return values[i1] < values[i2]; });

  return idx;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> x(N, 0);
  vector<int> y(N, 0);

  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }
  Graph<int> g(N, false);
  vector<int> xi = argsort(x);
  vector<int> yi = argsort(y);

  for (int i = 1; i < N; i++) {
    g.add_edge(xi[i - 1], xi[i], x[xi[i]] - x[xi[i - 1]]);
    g.add_edge(yi[i - 1], yi[i], y[yi[i]] - y[yi[i - 1]]);
  }

  Graph<int> p = g.spanning_tree();
  cout << p.get_total_weights() / 2 << endl;
  return 0;
}
