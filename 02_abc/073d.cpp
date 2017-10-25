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
  vector<vector<T>> shortest_paths();
  Graph<T> spanning_tree();
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

  int N, M, R;
  cin >> N >> M >> R;

  vector<int> r(R, 0);
  for (int i = 0; i < R; i++) {
    cin >> r[i];
    r[i]--;
  }

  Graph<int> g(N, false);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    g.add_edge(a, b, c);
  }

  vector<vector<int>> mat = g.shortest_paths();

  sort(r.begin(), r.end());
  int ma = INF;
  do {
    int total = 0;
    for (int i = 1; i < R; i++) {
      total += mat[r[i - 1]][r[i]];
    }
    ma = min(ma, total);
  } while (next_permutation(r.begin(), r.end()));

  cout << ma << endl;
  return 0;
}
