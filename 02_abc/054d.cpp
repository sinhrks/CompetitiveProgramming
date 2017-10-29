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

int a[41] = {};
int b[41] = {};
int c[41] = {};
int dp[41][410][410] = {};

const int INF = 100000;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  REP(i, N) {
    cin >> a[i] >> b[i] >> c[i];
  }

  REP(i, N) {
    REP(j, 410) {
      REP(k, 410) {
        dp[i][j][k] = INF;
      }
    }
  }

  REP(i, N) {
    REP(j, 410) {
      REP(k, 410) {
        if (i > 0 && dp[i - 1][j][k] < INF) {
          dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
          dp[i][j + a[i]][k + b[i]] = min(dp[i][j + a[i]][k + b[i]],
                                          dp[i - 1][j][k] + c[i]);
        }
      }
    }
    dp[i][a[i]][b[i]] = min(dp[i][a[i]][b[i]], c[i]);
  }
  int c = INF;
  for (int i = 1; i < 410; i++) {
    if (i * Ma >= 410 || i * Mb >= 410) break;
    c = min(c, dp[N - 1][i * Ma][i * Mb]);
  }

  if (c == INF) {
    cout << -1 << endl;
  } else {
    cout << c << endl;
  }
  return 0;
}
