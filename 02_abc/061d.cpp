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

// # define INF 0x3f3f3f3f             // int
const ll INF = 1LL << 50;  // ll

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
        if (!visited[e.dst]) container.push(e.dst);
      }
    }
    return all_of(visited.begin(), visited.end(),
                  [](bool v) { return v; });
  }
  // 木かどうか判定
  bool is_tree() {
    vector<bool> visited(V, false);
    queue<int> container;

    for (int i = 0; i < V; i++) {
      if (visited[i]) continue;
      container.push(i);
      while (!container.empty()) {
        int p = container.front();
        container.pop();
        visited[p] = true;
        for (const auto &e : adj[p]) {
          if (!visited[e.dst]) {
            container.push(e.dst);
          } else {
            return false;
          }
        }
      }
    }
    return true;
  }
  // 二部グラフ判定
  bool is_bipartite() {
    vector<int> visited(V, -1);
    queue<int> container;
    for (int i = 0; i < V; i++) {
      if (visited[i] != -1) continue;
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
    }
    return true;
  }
  pair<vector<bool>, vector<T>> shortest_path_neg(int s);
};

// 最短経路 (Bellman-Ford)
template <typename T>
pair<vector<bool>, vector<T>> Graph<T>::shortest_path_neg(int src) {
  vector<T> dist(V, INF);
  vector<bool> neg(V, false);
  dist[src] = 0;

  for (int i = 0; i < 2 * V; i++) {
    bool updated = false;
    for (int u = 0; u < V; u++) {
      if (dist[u] == INF) continue;
      for (const auto& e : adj[u]) {
        if (dist[e.dst] > dist[u] + e.weight) {
          dist[e.dst] = dist[u] + e.weight;
          updated = true;
          // 負閉路の有無だけなら i = V - 1 まで見れば十分
          if (i >= V - 1) neg[e.dst] = true;
        }
        if (neg[u]) neg[e.dst] = true;
      }
    }
    if (!updated) break;
  }
  return make_pair(neg, dist);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  Graph<ll> g(N, true);
  REP(i, M) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    g.add_edge(a, b, -c);
  }

  pair<vector<bool>, vector<ll>> p = g.shortest_path_neg(0);
  if (p.first[N - 1]) {
    cout << "inf" << endl;
  } else {
    cout << - p.second[N - 1] << endl;
  }
  return 0;
}
