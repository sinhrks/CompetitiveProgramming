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
