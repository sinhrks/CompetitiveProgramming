#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
class Graph {
 public:
  int V;    // 頂点数
  vector<Edge<T>> *adj;

  explicit Graph(int V) {
    this->V = V;
    adj = new vector<Edge<T>> [V];
  }
  void add_edge(int src, int dst, T weight) {
    assert(src >= 0 && src < V);
    assert(dst >= 0 && dst < V);
    adj[src].push_back(Edge<T>(src, dst, weight));
  }
  // vector<T> shortest_path(int s);
  Graph<T> spanning_tree();
};

// クラスカル法
template <typename T>
Graph<T> Graph<T>::spanning_tree() {
  Graph<T> result = Graph(V);
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    Graph<ll> g = Graph<ll>(N + 1);

    int c[100001] = {};
    for (int i = 0; i < N; i++) {
      cin >> c[i];
    }
    for (int i = 0; i < M; i++) {
      int a, b, r;
      cin >> a >> b >> r;
      g.add_edge(a, b, r);
    }

    for (int i = 0; i < N; i++) {
      g.add_edge(0, i + 1, c[i]);
    }

    Graph<ll> result = g.spanning_tree();
    ll total = 0;
    for (int i = 0; i < result.V; i++) {
      for (const auto& e : result.adj[i]) {
        total += e.weight;
      }
    }
    cout << total << endl;
    return 0;
}
