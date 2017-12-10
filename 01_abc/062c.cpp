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

int split(ll x, ll y) {
  ll diff = x * y;
  REP(i, 2) {
    ll x1 = x / 3 + i;
    // 縦
    REP(j, 2) {
      ll x2 = (x - x1) / 2 + j;
      ll x3 = x - x1 - x2;
      if (x1 == 0 || x2 == 0 || x3 == 0) continue;
      ll mina = min(min(x1, x2), x3) * y;
      ll maxa = max(max(x1, x2), x3) * y;
      // cout << x1 << " " << x2 << " " << x3 << endl;
      // cout << mina << " " << maxa << endl;
      // cout << endl;
      diff = min(diff, maxa - mina);
    }
    REP(j, 2) {
      ll x2 = x - x1;
      ll y2 = y / 2 + j;
      ll y3 = y - y2;
      if (x1 == 0 || x2 == 0 || y2 == 0 || y3 == 0) continue;
      ll mina = min(min(x1 * y, x2 * y2), x2 * y3);
      ll maxa = max(max(x1 * y, x2 * y2), x2 * y3);
      // cout << x1 << " " << x2 << " " << y2 << " " << y3 << endl;
      // cout << mina << " " << maxa << endl;
      // cout << endl;
      diff = min(diff, maxa - mina);
    }
  }
  return diff;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll H, W;
  cin >> H >> W;

  cout << min(split(H, W), split(W, H)) << endl;
  return 0;
}
