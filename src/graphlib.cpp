#include <assert.h>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;

#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

# define INF 0x3f3f3f3f             // int
// # define INF 0x3f3f3f3f3f3f3f3f  // ll

template <typename T>
struct Edge {
  int src, dst;
  T weight;
  Edge(int src, int dst) {
    this->src = src;
    this->dst = dst;
    this->weight = 1;
  }
  Edge(int src, int dst, T weight) : Edge::Edge(src, dst) {
    this->weight = weight;
  }
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
    if (src == dst) return 0;
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
  vector<T> shortest_path(int s);
  pair<vector<bool>, vector<T>> shortest_path_neg(int s);
  vector<vector<T>> shortest_paths();
  Graph<T> spanning_tree();
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
      if (dist[e.dst] > dist[u] + e.weight) {
        dist[e.dst] = dist[u] + e.weight;
        pq.push(Edge<T>(src, e.dst, dist[e.dst]));
      }
    }
  }
  return dist;
}

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

// 全点対間最小路 (Floyd Warshall)
template <typename T>
vector<vector<T>> Graph<T>::shortest_paths() {
  // dist[src][dst]に対応する距離が入る
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
 public:
  int n;
  vector<T> rank;

 protected:
  // それぞれの親を保持
  // グループを取得したい場合は root / get_group を使う
  vector<T> par;
  // 集合の大きさを保持
  // vector<int> siz;

 public:
  explicit UnionFind(int n) {
    this->n = n;
    par = vector<T>(n, 0);
    iota(par.begin(), par.end(), 0);
    rank = vector<T>(n, 0);
    // siz = vector<T>(n, 1);
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
      // siz[y] += siz[x];
    } else {
      par[y] = x;
      // siz[x] += siz[y];
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
  /*
  // 所属する集合の大きさを返す
  int get_group_size(T x) {
    return siz[root(x)];
  }
  */
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

// 最小全域木 (Kruskal)
template <typename T>
Graph<T> Graph<T>::spanning_tree() {
  Graph<T> result = Graph(V, directed);
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
struct FlowEdge : Edge<T> {
  T cap;
  int rev;
  FlowEdge(int src, int dst, T cap, int rev) : Edge<T>::Edge(src, dst) {
    this->cap = cap;
    this->rev = rev;
  }
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
  void add_edge(int src, int dst, T cap) {
    assert(src >= 0 && src < V);
    assert(dst >= 0 && dst < V);
    adj[src].push_back(FlowEdge<T>(src, dst, cap, (int)adj[dst].size()));
    adj[dst].push_back(FlowEdge<T>(dst, src, 0, (int)adj[src].size() - 1));
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
        if (e.cap > 0 && level[e.dst] < 0) {
          level[e.dst] = level[v] + 1;
          que.push(e.dst);
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
    for (int &i = iter[v]; i < static_cast<int>(adj[v].size()); i++) {
      FlowEdge<T> &e = adj[v][i];
      if (e.cap > 0 && level[v] < level[e.dst]) {
        int d = dfs(e.dst, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          adj[e.dst][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  // sからtへの最大流を求める (Dinic法)
  int max_flow(int s, int t) {
    int flow = 0;
    while (true) {
      bfs(s);
      if (level[t] < 0) return flow;
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

  assert(g.get_weight(0, 0) == 0);
  assert(g.get_weight(2, 2) == 0);
  assert(g.get_weight(1, 2) == INF);

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

void test_is_bipartite() {
  Graph<int> g(5, false);
  assert(g.is_bipartite());
  g.add_edge(0, 1, 1);
  assert(g.is_bipartite());
  g.add_edge(0, 2, 1);
  g.add_edge(3, 1, 1);
  g.add_edge(3, 2, 1);
  assert(g.is_bipartite());
  g.add_edge(1, 2, 1);
  assert(!g.is_bipartite());
  g.remove_edge(1, 2);
  assert(g.is_bipartite());
  g.add_edge(0, 3, 1);
  assert(!g.is_bipartite());
}

void test_shortest_path() {
  Graph<int> g(4, true);
  g.add_edge(0, 1, 2);
  g.add_edge(0, 2, 3);
  g.add_edge(2, 3, 4);
  g.add_edge(0, 3, 100);
  vector<int> p = g.shortest_path(0);
  vector<int> edist = {0, 2, 3, 7};
  assert(p == edist);
}

void test_shortest_path_neg() {
  Graph<int> g(4, true);
  g.add_edge(0, 1, 2);
  g.add_edge(0, 2, 3);
  g.add_edge(2, 3, 4);
  g.add_edge(0, 3, 100);
  pair<vector<bool>, vector<int>> p = g.shortest_path_neg(0);
  vector<bool> nflag = {false, false, false, false};
  assert(p.first == nflag);
  vector<int> edist = {0, 2, 3, 7};
  assert(p.second == edist);
}

void test_shortest_path_neg2() {
  Graph<int> g(4, true);
  g.add_edge(0, 1, 2);
  g.add_edge(2, 0, 3);
  g.add_edge(1, 2, -10);
  pair<vector<bool>, vector<int>> p = g.shortest_path_neg(0);
  vector<bool> nflag = {true, true, true, false};
  assert(p.first == nflag);
  vector<int> edist = {-40, -33, -43, INF};
  assert(p.second == edist);
}

void test_spanning_tree() {
  Graph<int> g(7, false);
  g.add_edge(0, 2, 1);
  g.add_edge(1, 2, 2);
  g.add_edge(2, 3, 3);
  g.add_edge(1, 4, 10);
  g.add_edge(4, 5, 5);
  g.add_edge(2, 5, 7);
  g.add_edge(3, 5, 1);
  g.add_edge(3, 6, 5);
  g.add_edge(5, 6, 8);
  Graph<int> s = g.spanning_tree();
  assert(s.get_total_weights() == 34);
}

void test_max_flow() {
  FlowGraph<int> g(5);
  g.add_edge(0, 1, 10);
  g.add_edge(0, 2, 2);
  g.add_edge(1, 2, 6);
  g.add_edge(1, 3, 6);
  g.add_edge(3, 2, 3);
  g.add_edge(3, 4, 8);
  g.add_edge(2, 4, 5);
  assert(g.max_flow(0, 4) == 11);
}

int main() {
  test_connected_directed();
  test_connected_undirected();
  test_is_bipartite();

  test_shortest_path();

  test_shortest_path_neg();
  test_shortest_path_neg2();

  test_spanning_tree();

  test_max_flow();

  cout << "SUCCESS!!" << endl;
  return 0;
}
