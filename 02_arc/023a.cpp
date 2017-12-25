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

int get_dt(int y, int m, int d) {
  return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int y, m, d;
  cin >> y >> m >> d;
  if (m <= 2) {
    m += 12;
    y--;
  }

  int ans = abs(get_dt(y, m, d) - get_dt(2014, 5, 17));
  cout << ans << endl;
  return 0;
}
