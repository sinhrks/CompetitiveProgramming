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

using namespace std;

const ll MOD7 = 1000000007;
ll x[100010] = {};
ll y[100010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> y[i];
  }

  ll xx = 0;
  for (int i = 1; i <= n; i++) {
    xx += (i - 1) * x[i] - (n - i) * x[i];
    xx %= MOD7;
  }
  ll yy = 0;
  for (int i = 1; i <= m; i++) {
    yy += (i - 1) * y[i] - (m - i) * y[i];
    yy %= MOD7;
  }

  cout << xx * yy % MOD7 << endl;
  return 0;
}
