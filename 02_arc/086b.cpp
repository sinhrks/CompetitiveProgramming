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

  int N;
  cin >> N;

  int a[51] = {};
  pair<int, int> pat[110] = {};

  REP(i, N) {
    cin >> a[i];
  }
  int mi = a[0];
  int ma = a[0];
  int mii = 0;
  int mai = 0;
  REP(i, N) {
    if (mi > a[i]) {
      mi = a[i];
      mii = i;
    }
    if (ma < a[i]) {
      ma = a[i];
      mai = i;
    }
  }
  if (ma == mi) {
    cout << 0 << endl;
    return 0;
  }

  int p = 0;
  if (abs(ma) >= abs(mi)) {
    REP(i, N) {
      if (a[i] <= 0) {
        pat[p++] = make_pair(mai, i);
        a[i] += ma;
      }
    }
    REP(i, N - 1) {
      if (a[i] <= a[i + 1]) continue;
      pat[p++] = make_pair(i, i + 1);
      a[i + 1] += a[i];
    }
  } else {
    REP(i, N) {
      if (a[i] >= 0) {
        pat[p++] = make_pair(mii, i);
        a[i] += mi;
      }
    }
    REPR(i, N - 1) {
      if (a[i] <= a[i + 1]) continue;
      pat[p++] = make_pair(i + 1, i);
      a[i] += a[i + 1];
    }
  }
  cout << p << endl;
  REP(i, p) {
    cout << pat[i].first + 1 << " " << pat[i].second + 1 << endl;
  }
  return 0;
}
