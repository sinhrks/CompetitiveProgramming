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

// 辺を表す構造体 (行き先、容量、逆辺)
struct edge { int to, cap, rev; };

const int MAX_V = 110;

vector<edge> G[MAX_V];   // グラフの隣接リスト表現
bool used[MAX_V];        // DFSですでに調べたかのフラグ

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
  G[from].push_back((edge){to, cap, (int)G[to].size()});
  G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}

// 増加パスをDFSで探す
int dfs(int v, int t, int f) {
  if (v == t) return f;
  used[v] = true;

  for (int i = 0; i < G[v].size(); i++) {
    edge &e = G[v][i];
    if (!used[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap)); if (d > 0) {
        e.cap -= d; G[e.to][e.rev].cap += d; return d;
      }
    }
  }
  return 0;
}

const int INF = 1000000;

// sからtへの最大流を求める
int max_flow(int s, int t) {
  int flow = 0;
  for (;;) {
    memset(used, 0, sizeof(used));
    int f = dfs(s, t, INF);
    if (f == 0) return flow;
    flow += f;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, G_, E;
  cin >> N >> G_ >> E;

  for (int i = 0; i < G_; i++) {
    int p_;
    cin >> p_;
    add_edge(p_, 101, 1);
  }

  for (int i = 0; i < E; i++) {
    int a, b;
    cin >> a >> b;
    add_edge(a, b, 1);
    add_edge(b, a, 1);
  }

  int x = max_flow(0, 101);

  cout << x << endl;
  return 0;
}
