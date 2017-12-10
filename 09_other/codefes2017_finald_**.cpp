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


ll P[5010] = {};
ll H[5010] = {};
ll dp[5010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<pair<ll, ll>> vals;
  REP(i, N) {
    ll h, p;
    cin >> h >> p;
    vals.push_back(make_pair(p, h));
  }
  sort(vals.begin(), vals.end());

  ll c = 0;
  int ma = 0;
  for (auto v : vals) {
    if (c <= v.second) {
      ma++;
      c += v.first;
    }
  }
  /*

  REP(i, 5010) {
    dp[i] = INF;
  }
  dp[0] = 0;

  REP(i, N) {
    REPR(j, N) {
      if (j > 0) {
        if (dp[j - 1] <= H[i]) {
          dp[j] = min(dp[j - 1] + P[i], dp[j]);
        }
      }
    }
  }
  int ma = 0;
  REP(i, N + 1) {
    if (dp[i] != INF) ma = i;
  }
  */

  cout << ma << endl;
  return 0;
}
