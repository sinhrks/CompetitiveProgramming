#include <assert.h>
#include <iostream>
#include <queue>
#include <vector>

typedef long long ll;

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
  vector<T> shortest_path(int s);
  vector<vector<T>> shortest_paths();
  Graph<T> spanning_tree();
};

// 最短経路(ダイクストラ法)
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

// 最小全域木 (クラスカル法)
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

// 辺を表す構造体 (行き先、容量、逆辺)
template <typename T>
struct FlowEdge {
  int to, rev;
  T cap;
  FlowEdge(int to, T cap, int rev) :
    to(to), cap(cap), rev(rev) { }
};

template <typename T>
struct FlowGraph {
  // 頂点数
  int V;
  // グラフの隣接リスト表現
  vector<FlowEdge<T>> *adj;
  vector<int> level;
  vector<int> iter;

  explicit FlowGraph(int V) {
    this-> V = V;
    adj = new vector<FlowEdge<T>> [V];
    level = vector<int>(V, -1);
    iter = vector<int>(V, 0);
  }

  // fromからtoへ向かう容量capの辺をグラフに追加する
  void add_edge(int from, int to, T cap) {
    adj[from].push_back(FlowEdge<T>(to, cap, (int)adj[to].size()));
    adj[to].push_back(FlowEdge<T>(from, 0, (int)adj[from].size() - 1));
  }

  // sからの最短距離をBFSで計算する
  void bfs(int s) {
    fill(level.begin(), level.end(), -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (const auto& e : adj[v]) {
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }
  // 増加パスをDFSで探す
  int dfs(int v, int t, int f) {
    if (v == t) {
      return f;
    }
    // iter[v] からループを回す
    for (int &i = iter[v]; i < adj[v].size(); i++) {
      FlowEdge<T> &e = adj[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        int d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          adj[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  // sからtへの最大流を求める
  int max_flow(int s, int t) {
    int flow = 0;
    while (true) {
      bfs(s);
      if (level[t] < 0) {
        return flow;
      }
      fill(iter.begin(), iter.end(), 0);
      int f;
      while ((f = dfs(s, t, INF)) > 0) {
        flow += f;
      }
    }
  }
};

void test_connected_directed() {
  Graph<int> g(3, true);

  g.add_edge(0, 1, 1);
  assert(g.has_edge(0, 1));
  assert(g.get_weight(0, 1) == 1);
  assert(g.get_total_weights() == 1);

  assert(!g.has_edge(1, 0));
  assert(g.get_weight(1, 0) == INF);
  assert(!g.is_connected());

  g.add_edge(1, 2, 3);
  assert(g.has_edge(1, 2));
  assert(g.get_weight(1, 2) == 3);
  assert(g.get_total_weights() == 4);

  assert(!g.has_edge(2, 1));
  assert(g.get_weight(2, 1) == INF);
  assert(g.is_connected());

  g.add_edge(2, 1, 2);
  assert(g.has_edge(2, 1));
  assert(g.get_weight(2, 1) == 2);
  assert(g.get_total_weights() == 6);

  g.remove_edge(1, 2);
  assert(!g.has_edge(1, 2));
  assert(g.get_weight(1, 2) == INF);

  assert(g.has_edge(2, 1));
  assert(g.get_weight(2, 1) == 2);
  assert(g.get_total_weights() == 3);
}

void test_connected_undirected() {
  Graph<int> g(3, false);

  g.add_edge(0, 1, 1);
  assert(g.has_edge(0, 1));
  assert(g.get_weight(0, 1) == 1);
  assert(g.get_total_weights() == 2);

  assert(g.has_edge(1, 0));
  assert(g.get_weight(1, 0) == 1);
  assert(!g.is_connected());

  g.add_edge(1, 2, 3);
  assert(g.has_edge(1, 2));
  assert(g.get_weight(1, 2) == 3);
  assert(g.get_total_weights() == 8);

  assert(g.has_edge(2, 1));
  assert(g.get_weight(2, 1) == 3);
  assert(g.is_connected());

  g.remove_edge(1, 2);
  assert(!g.has_edge(1, 2));
  assert(g.get_weight(1, 2) == INF);

  assert(!g.has_edge(2, 1));
  assert(g.get_weight(2, 1) == INF);
  assert(!g.is_connected());
  assert(g.get_total_weights() == 2);
}

int main() {
  test_connected_directed();
  test_connected_undirected();

  cout << "SUCCESS!!" << endl;
  return 0;
}
