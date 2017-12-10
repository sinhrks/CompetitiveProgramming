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


# define INF 0x3f3f3f3f             // int
// # define INF 0x3f3f3f3f3f3f3f3f  // ll

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
  // 辺の重みを取得
  T get_weight(int src, int dst) {
    for (const auto& e : adj[src]) {
      if (e.dst == dst) {
        return e.weight;
      }
    }
    return INF;
  }
  // 辺の重みの合計を取得
  ll get_total_weights() {
    ll result = 0;
    for (int i = 0; i < V; i++) {
      for (const auto& e : adj[i]) {
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
      for (const auto& e : adj[p]) {
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
        for (const auto& e : adj[p]) {
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
        for (const auto& e : adj[p]) {
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
  // src からの深さをBFSで計算する
  // (weight の大きさは考慮しない)
  vector<int> get_depth_bfs(int src) {
    vector<int> depth(V, -1);
    queue<int> container;
    container.push(src);
    depth[src] = 0;

    while (!container.empty()) {
      int v = container.front();
      container.pop();
      for (const auto& e : adj[v]) {
        if (e.weight != 0 && depth[e.dst] < 0) {
          depth[e.dst] = depth[v] + 1;
          container.push(e.dst);
        }
      }
    }
    return depth;
  }
  vector<vector<T>> shortest_paths();
};


// 全点対間最小路 (Floyd Warshall)
template <typename T>
vector<vector<T>> Graph<T>::shortest_paths() {

  vector<vector<T>> dist = vector<vector<T>>(V, vector<T>(V, INF));

  for (int i = 0; i < V; i++) {
    for (int j = 0 ; j < V; j++) {
      dist[i][j] = get_weight(i, j);
    }
  }

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      for (int k = 0; k < V; k++) {
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }
  return dist;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  Graph<int> g(N, false);
  REP(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    g.add_edge(a, b, c);
  }
  vector<vector<int>> dist = g.shortest_paths();
  int cnt = 0;
  REP(i, N) {
    for (auto e : g.adj[i]) {
      if (e.weight > dist[e.dst][e.src]) cnt++;
    }
  }

  cout << cnt / 2 << endl;
  return 0;
}
