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


const int INF = 1000000;

// 辺を表す構造体 (行き先、容量、逆辺)
template <typename T>
struct FlowEdge {
  int to, rev;
  T cap;
  FlowEdge(int to, T cap, int rev) :
    to(to), cap(cap), rev(rev) { }
};

template <typename T>
class FlowGraph {
 public:
  // 頂点数
  int V;
  // グラフの隣接リスト表現
  vector<FlowEdge<T>> *adj;
  vector<int> level;
  vector<int> iter;

  explicit FlowGraph(int V) {
    this-> V = V;
    adj = new vector<FlowEdge<T>> [V];
    level = vector<int>(V, -1);
    iter = vector<int>(V, 0);
  }

  // fromからtoへ向かう容量capの辺をグラフに追加する
  void add_edge(int from, int to, T cap) {
    adj[from].push_back(FlowEdge<T>(to, cap, (int)adj[to].size()));
    adj[to].push_back(FlowEdge<T>(from, 0, (int)adj[from].size() - 1));
  }

  // sからの最短距離をBFSで計算する
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
  // 増加パスをDFSで探す
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


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, G_, E;
  cin >> N >> G_ >> E;

  FlowGraph<int> fg = FlowGraph<int>(110);

  for (int i = 0; i < G_; i++) {
    int p_;
    cin >> p_;
    fg.add_edge(p_, 101, 1);
  }

  for (int i = 0; i < E; i++) {
    int a, b;
    cin >> a >> b;
    fg.add_edge(a, b, 1);
    fg.add_edge(b, a, 1);
  }

  int x = fg.max_flow(0, 101);

  cout << x << endl;
  return 0;
}
