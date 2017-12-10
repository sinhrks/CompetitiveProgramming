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

const double EPS = 1e-8;

using namespace std;

double dist2(int x1, int x2, int y1, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int txa, tya, txb, tyb, T, V, N;
  cin >> txa >> tya >> txb >> tyb >> T >> V;
  cin >> N;

  double d2 = 1.0 * T * V;
  bool flag = false;
  REP(i, N) {
    int x, y;
    cin >> x >> y;
    if (dist2(txa, x, tya, y) + dist2(txb, x, tyb, y) < d2 + EPS) {
      // cout << d2;
      flag = true;
    }
  }
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
