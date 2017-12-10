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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, W;
  cin >> N >> W;

  ll w[110] = {};
  ll v[110] = {};
  REP(i, N) {
    cin >> w[i] >> v[i];
  }

  vector<vector<ll>> d = vector<vector<ll>>(4, vector<ll>());
  ll w0 = w[0];
  d[0].push_back(v[0]);
  for (int i = 1; i < N; i++) {
    d[w[i] - w[0]].push_back(v[i]);
  }
  REP(i, 4) {
    sort(d[i].begin(), d[i].end(), greater<ll>());
    // DEBUG(d[i]);
    for (int j = 1; j < d[i].size(); j++) {
      d[i][j] = d[i][j - 1] + d[i][j];
    }
  }

  ll mx = 0;
  REP(i, d[0].size() + 1) {
    REP(j, d[1].size() + 1) {
      REP(k, d[2].size() + 1) {
        REP(l, d[3].size() + 1) {
          ll w = w0 * i + (w0 + 1) * j + (w0 + 2) * k + (w0 + 3) * l;
          // cout << "weight: " << w << endl;
          if (w <= W) {
            ll total = 0;
            if (i > 0) total += d[0][i - 1];
            if (j > 0) total += d[1][j - 1];
            if (k > 0) total += d[2][k - 1];
            if (l > 0) total += d[3][l - 1];
            mx = max(mx, total);
          }
        }
      }
    }
  }

  cout << mx << endl;
  return 0;
}
