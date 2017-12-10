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

# define INF 0x3f3f3f3f

int N, Z, W;

ll A[2010] = {};
ll dp[2010][2] = {};

ll solve(int idx, int player, ll s1, ll s2) {
  if (idx == N) return abs(s1 - s2);
  if (dp[idx][player] != -1) return dp[idx][player];

  if (player == 0) {
    ll score = -1;
    for (int i = idx; i < N; i++) {
      score = max(score, solve(i + 1, 1, A[i], s2));
    }
    dp[idx][player] = score;
    return score;
  } else {
    ll score = INF;
    for (int i = idx; i < N; i++) {
      score = min(score, solve(i + 1, 0, s1, A[i]));
    }
    dp[idx][player] = score;
    return score;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> Z >> W;
  REP(i, N) {
    cin >> A[i];
  }

  REP(i, N) {
    REP(j, 2) {
      dp[i][j] = -1;
    }
  }
  ll score = solve(0, 0, Z, W);
  cout << score << endl;
  return 0;
}
