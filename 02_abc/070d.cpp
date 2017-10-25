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

// # define INF 0x3f3f3f3f
# define INF 0x3f3f3f3f3f3f3f3f

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
  // 二部グラフ判定
  bool is_bipartite() {
    vector<int> visited(V, -1);
    queue<int> container;
    container.push(0);
    visited[0] = 1;
    while (!container.empty()) {
      int p = container.front();
      container.pop();
      for (const auto &e : adj[p]) {
        if (visited[e.dst] == -1) {
          visited[e.dst] = (visited[p] + 1) % 2;
          container.push(e.dst);
        } else if (visited[e.dst] == visited[p]) {
          return false;
        }
      }
    }
    // 連結でない場合は false
    return all_of(visited.begin(), visited.end(),
                  [](int v) { return v >= 0; });
  }
  vector<T> shortest_path(int s);
};

// 最短経路 (Dijkstra)
template <typename T>
vector<T> Graph<T>::shortest_path(int src) {
  priority_queue<Edge<T>> pq;
  vector<T> dist(V, INF);

  pq.push(Edge<T>(src, src, 0));
  dist[src] = 0;

  while (!pq.empty()) {
    int u = pq.top().dst;
    pq.pop();

    for (const auto& e : adj[u]) {
        int v = e.dst;
        T weight = e.weight;

        if (dist[v] > dist[u] + weight) {
          dist[v] = dist[u] + weight;
          pq.push(Edge<T>(src, e.dst, dist[v]));
        }
    }
  }
  return dist;
}

int X[100010] = {};
int Y[100010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  Graph<ll> g(N, false);

  REP(i, N - 1) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    g.add_edge(a, b, c);
  }

  int Q, K;
  cin >> Q >> K;
  K--;

  vector<ll> dist = g.shortest_path(K);
  // DEBUG(dist);

  REP(i, Q) {
    cin >> X[i] >> Y[i];
    X[i]--;
    Y[i]--;
  }
  REP(i, Q) {
    cout << dist[X[i]] + dist[Y[i]] << endl;
  }
  return 0;
}
