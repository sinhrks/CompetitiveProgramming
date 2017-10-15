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
typedef unsigned long long ull;

using namespace std;

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
      for (auto e : adj[p]) {
        if (!visited[e.dst]) {
          container.push(e.dst);
        }
      }
    }
    return all_of(visited.begin(), visited.end(),
                  [](bool v) { return v; });
  }
  // vector<T> shortest_path(int s);
  // vector<vector<T>> shortest_paths();
  // Graph<T> spanning_tree();
};

bool adj[51][51] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  Graph<int> g(N, false);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g.add_edge(a, b, 1);
  }

  int result = 0;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (g.has_edge(i, j)) {
        g.remove_edge(i, j);
        if (!g.is_connected()) {
          result++;
        }
        g.add_edge(i, j, 1);
      }
    }
  }

  cout << result << endl;
  return 0;
}
