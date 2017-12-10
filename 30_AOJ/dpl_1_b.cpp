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

# define INF 0x3f3f3f3f

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, W;
  cin >> N >> W;

  int v[110] = {};
  int w[110] = {};

  REP(i, N) {
    cin >> v[i] >> w[i];
  }
  int dp[10010] = {};

  REP(i, N) {
    REPR(j, W) {
      if (dp[j] > 0 && j + w[i] <= W) {
        dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
      }
    }
    dp[w[i]] = max(dp[w[i]], v[i]);
  }
  int ma = 0;
  REP(i, W + 1) {
    ma = max(dp[i], ma);
  }

  cout << ma << endl;
  return 0;
}
