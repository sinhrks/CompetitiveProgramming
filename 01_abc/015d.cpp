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

  int W, N, K;
  cin >> W >> N >> K;

  int A[51] = {};
  int B[51] = {};
  for (int i = 1; i <= N; i++) {
    cin >> A[i] >> B[i];
  }

  int dp[10010][51] = {};

  for (int i = 1; i <= N; i++) {
    REPR(j, W) {
      for (int k = 1; k < i; k++) {
        if (dp[j][k] > 0 && k < K && j + A[i] <= W) {
          dp[j + A[i]][k + 1] = max(dp[j + A[i]][k + 1], dp[j][k] + B[i]);
        }
      }
    }
    dp[A[i]][1] = max(dp[A[i]][1], B[i]);
  }
  int ma = 0;
  REP(i, K + 1) {
    REP(j, W + 1) {
      ma = max(dp[j][i], ma);
    }
  }
  cout << ma << endl;
  return 0;
}
