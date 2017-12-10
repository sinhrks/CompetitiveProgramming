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

  explicit Graph(int V) {
    this->V = V;
    adj = new vector<Edge<T>> [V];
  }
  void add_edge(int src, int dst, T weight) {
    assert(src >= 0 && src < V);
    assert(dst >= 0 && dst < V);
    adj[src].push_back(Edge<T>(src, dst, weight));
  }
  vector<T> shortest_path(int s);
  // vector<vector<T>> shortest_paths();
  // Graph<T> spanning_tree();
};

template <typename T>
vector<T> Graph<T>::shortest_path(int src) {
  vector<T> dist(V, INF);
  dist[src] = 0;

  for (int i = 0; i < V; i++) {
    bool updated = false;
    for (int u = 0; u < V; u++) {
      for (const auto& e : adj[u]) {
        if (dist[u] != INF && dist[e.dst] > dist[u] + e.weight) {
          dist[e.dst] = dist[u] + e.weight;
          updated = true;
          if (i == V - 1) {
            dist = vector<T>(V, -INF);
            return dist;
          }
        }
      }
    }
    if (!updated) break;
  }
  return dist;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;

  Graph<int> g(N);

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    g.add_edge(a - 1, b - 1, 1);
    g.add_edge(b - 1, a - 1, 1);
  }

  vector<int> dist1 = g.shortest_path(0);
  vector<int> dist2 = g.shortest_path(N - 1);

  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 0; i < N; i++) {
    if (dist1[i] <= dist2[i]) {
      cnt1++;
    } else {
      cnt2++;
    }
  }
  if (cnt1 > cnt2) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }
  return 0;
}
