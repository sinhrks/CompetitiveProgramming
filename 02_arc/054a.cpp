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

  ll L, X, Y, S, D;
  cin >> L >> X >> Y >> S >> D;

  double ans;
  if (S < D) {
    ans = 1.0 * (D - S) / (Y + X);
    if (Y > X) {
      ans = min(ans, 1.0 * (S + L - D) / (Y - X));
    }
  } else {
    ans = 1.0 * (D + L - S) / (Y + X);
    if (Y > X) {
      ans = min(ans, 1.0 * (S - D) / (Y - X));
    }
  }
  printf("%.10f\n", ans);
  return 0;
}
