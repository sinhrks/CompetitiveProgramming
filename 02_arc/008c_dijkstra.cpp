#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
  int V;    // 頂点数
  vector<Edge<T>> *adj;

 public:
  explicit Graph(int V);
  void add_edge(int src, int dst, T weight);
  vector<T> shortest_path(int s);
};

template <typename T>
Graph<T>::Graph(int V) {
  this->V = V;
  adj = new vector<Edge<T>> [V];
}

template <typename T>
void Graph<T>::add_edge(int src, int dst, T weight) {
  adj[src].push_back(Edge<T>(src, dst, weight));
}

// ダイクストラ法
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


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  ll xs[1000];
  ll ys[1000];
  int ts[1000];
  int rs[1000];
  for (int i = 0; i < N; i++) {
    ll x, y;
    int t, r;
    cin >> x >> y >> t >> r;
    xs[i] = x;
    ys[i] = y;
    ts[i] = t;
    rs[i] = r;
  }

  Graph<double> g(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) {
        continue;
      }
      int vel = min(ts[i], rs[j]);
      double dist = sqrt((xs[i] - xs[j]) * (xs[i] - xs[j]) +
                         (ys[i] - ys[j]) * (ys[i] - ys[j]));
      double tm = dist / vel;
      g.add_edge(i, j, tm);
    }
  }

  vector<double> dist = g.shortest_path(0);
  sort(dist.begin(), dist.end());
  reverse(dist.begin(), dist.end());
  double tm = 0;
  for (int i = 0; i < N - 1; i++) {
    tm = max(tm, i + dist[i]);
  }
  printf("%.10f\n", tm);
  return 0;
}
