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
#define INF 0x3f3f3f3f


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
  T get_edge(int src, int dst) {
    for (const auto& e : adj[src]) {
      if (e.dst == dst) {
        return e.weight;
      }
    }
    return INF;
  }
  vector<vector<T>> shortest_path();
  // Graph<T> spanning_tree();
};


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  Graph<int> g(N);

  vector<vector<int>> orig = vector<vector<int>>(N, vector<int>(N, INF));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int a;
      cin >> a;
      orig[i][j] = a;
      g.add_edge(i, j, a);
    }
  }

  vector<vector<int>> dist = vector<vector<int>>(N, vector<int>(N, INF));
  vector<vector<bool>> needed = vector<vector<bool>>(N, vector<bool>(N, true));
  for (int i = 0; i < N; i++) {
    for (int j = 0 ; j < N; j++) {
      dist[i][j] = g.get_edge(i, j);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (i != j && i != k && dist[j][k] == dist[j][i] + dist[i][k]) {
          needed[j][k] = false;
        }
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }

  int total = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (orig[i][j] != dist[i][j]) {
        cout << -1 << endl;
        return 0;
      }
      if (needed[i][j]) {
        total += orig[i][j];
      }
    }
  }

  cout << total << endl;
  return 0;
}
