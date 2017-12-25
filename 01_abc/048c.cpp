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

int a[100010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, x;
  cin >> N >> x;
  REP(i, N) {
    cin >> a[i];
  }
  ll ans = 0;
  if (a[0] > x) {
    ans += a[0] - x;
    a[0] = x;
  }
  REP(i, N - 1) {
    if (a[i] + a[i + 1] > x) {
      int diff = a[i] + a[i + 1] - x;
      ans += diff;
      a[i + 1] -= diff;
    }
  }

  cout << ans << endl;
  return 0;
}
