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

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

int H, W;
ll trial = 0;

bool visited[11][11] = {};
ll dist[11][11] = {};
char maze[11][11] = {};

void clear() {
  REP(i, 11) {
    REP(j, 11) {
      visited[i][j] = false;
      dist[i][j] = 0;
    }
  }
}

// 右、下、左、上
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll dfs(int x, int y, ll d) {
  // cout <<"d: " << x << " " << y << " " << d << endl;

  if (maze[y][x] == 'G') {
    return d + 1;
  }
  visited[y][x] = true;
  dist[y][x] = d;

  ll mi = 1000000010;
  REP(i, 4) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
      ll tmp = d;
      if (maze[ny][nx] == '.') {
        tmp += 1;
      } else if (maze[ny][nx] == '#') {
        tmp += trial;
      }
      if (!visited[ny][nx] || tmp < dist[ny][nx]) {
        mi = min(mi, dfs(nx, ny, tmp));
      }
    }

  }
  return mi;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll T;
  cin >> H >> W >> T;
  REP(i, H) {
    string s;
    cin >> s;
    REP(j, W) {
      maze[i][j] = s[j];
    }
  }
  int sx, sy;
  REP(i, H) {
    REP(j, W) {
      if (maze[i][j] == 'S') {
        sx = j;
        sy = i;
      }
    }
  }
  ll left = 1;
  ll right = 1000000010;

  while (right - left > 1) {
    trial = (left + right) / 2;
    clear();
    // cout << trial << " " << dfs(sx, sy, 0) << endl;
    if (dfs(sx, sy, 0) <= T) {
      left = trial;
    } else {
      right = trial;
    }
  }

  cout << left << endl;
  return 0;
}
